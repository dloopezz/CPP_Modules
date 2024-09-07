/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:43:10 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/05 16:54:46 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	return;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	*this = copy;
	return;
}
BitcoinExchange::~BitcoinExchange()
{
	return;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		database = other.database;
	return *this;
}

void trimSpaces(std::string &s)
{
	s.erase(0, s.find_first_not_of(" \t"));
	s.erase(s.find_last_not_of(" \t") + 1);
}

int BitcoinExchange::checkDate(std::string date)
{
	int posYearMonth = date.find('-');
	int posMonthDay = date.rfind('-');

	if (posYearMonth == posMonthDay)
		return 1;
	
	std::string yearStr = date.substr(0, posYearMonth);
	std::string monthStr = date.substr(posYearMonth + 1, posMonthDay - posYearMonth - 1);
	std::string dayStr = date.substr(posMonthDay + 1, date.npos);

	if (yearStr.size() != 4 || monthStr.size() != 2 || dayStr.size() != 2)
		return 1;

	char *endPtr = NULL;
	yearStr = strtol(yearStr.c_str(), &endPtr, 10);
	if (*endPtr)
		return 1;
		
	long month = strtol(monthStr.c_str(), &endPtr, 10);
	if (*endPtr || (month < 1 || month > 12))
		return 1;

	long day = strtol(dayStr.c_str(), &endPtr, 10);
	if (*endPtr || (day < 1 || day > 31))
		return 1;
	
	return 0;

}

void BitcoinExchange::parseDatabase(std::string databasePath)
{
	std::ifstream databaseFile(databasePath);
	std::string line;

	if (databaseFile.fail())
		throw BitcoinExchange::openFileException();

	std::getline(databaseFile, line);
	while (std::getline(databaseFile, line))
	{
		size_t pos = line.find(',');
		
		if (pos == std::string::npos)
			throw BitcoinExchange::parsingException();
		
		std::string date = line.substr(0, pos);
		trimSpaces(date);
		std::string valueStr = line.substr(pos + 1, line.npos);
		trimSpaces(valueStr);
		char *endPtr = NULL;
		double value = strtod(valueStr.c_str(), &endPtr);
		
		if (*endPtr || checkDate(date))
			throw BitcoinExchange::parsingException();
			
		database.insert(std::make_pair(date, value));
	}
	databaseFile.close();
}

void BitcoinExchange::calcExchange(std::string inputPath)
{
	parseDatabase("data.csv");

	std::ifstream inputFile(inputPath);
	if (inputFile.fail())
		throw BitcoinExchange::openFileException();
	
	std::string line;
	std::getline(inputFile, line);

	while (std::getline(inputFile, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::string date = line.substr(0, pos);
		trimSpaces(date);
		if (checkDate(date))
		{
			std::cout << "Error:  => " << date << std::endl;
			continue;
		}

		std::string btcStr = line.substr(pos + 1, line.npos);
		trimSpaces(btcStr);
		char *endPtr;
		double btc = strtod(btcStr.c_str(), &endPtr);
		if (*endPtr)
		{
			std::cout << "Error: bad input => " << btc << std::endl;
			continue;
		}
		if (btc > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		if (btc < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		
		std::map<std::string, double>::iterator i = database.upper_bound(date);
		if (i == database.begin())
		{
			std::cout << "Error: no value found => " << date << '\n';
			continue;
		}
		
		std::pair<std::string, double> elem = *(--i);

		double total = btc * elem.second;
		std::cout << date << " => " << btc << " = " << total << std::endl;
	}
}
