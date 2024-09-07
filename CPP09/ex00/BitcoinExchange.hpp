/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:26:47 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/04 19:20:44 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double> database;
		
		class openFileException : public std::exception {
			const char* what() const throw() {
				return "Error: Cannot open file";
			}
		};
		
		class parsingException : public std::exception {
			const char* what() const throw() {
				return "Error: parsing error.";
			}
		};
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &other);
		
		void	parseDatabase(std::string databasePath);
		int		checkDate(std::string date);
		void	calcExchange(std::string inputPath);
		
};

#endif