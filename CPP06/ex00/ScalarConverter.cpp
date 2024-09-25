/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:25:47 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/24 17:54:53 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	return ;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	(void) copy;
	return ;
}

ScalarConverter::~ScalarConverter()
{
	return ;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &assign)
{
	(void) assign;
	return *this;
}

static void floatSpecialCase(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
}

static void doubleSpecialCase(std::string str)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

static void writeNumber(int intCase, float floatCase, double doubleCase)
{
	//Print Char
	if (intCase > 31 && intCase < 127 && isprint(intCase)) //caracteres ASCII imprimibles
		std::cout << "char: " << static_cast<char>(intCase) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	//Print int
	if (doubleCase >= INT_MIN && doubleCase <= INT_MAX)
		std::cout << "int: " << static_cast<int>(doubleCase) << std::endl;
	else	
		std::cout << "int: impossible" << std::endl;

	//Print float
	float floatAux;
	if (std::modf(floatCase, &floatAux) == 0.0f)
		std::cout << "float: " << floatCase << ".0f" << std::endl;
	else
		std::cout << "float: " << floatCase << "f" << std::endl;

	//Print double
	double doubleAux;
	if (std::modf(doubleCase, &doubleAux) == 0.0)
		std::cout << "double: " << doubleCase << ".0" << std::endl;
	else
		std::cout << "double: " << doubleCase << std::endl;
}

static void selectWriter(char *str, int type)
{
	int intCase;
	float floatCase;
	double doubleCase;

	switch (type)
	{
		case 2:
			writeNumber(static_cast<int>(str[0]), static_cast<float>(str[0]), static_cast<double>(str[0]));
			break;
		case 3:
			intCase = atoi(str);
			writeNumber(intCase, static_cast<float>(intCase), static_cast<double>(intCase));
			break;
		case 4:
			floatCase = strtof(str, NULL);
			writeNumber(static_cast<int>(floatCase), floatCase, static_cast<double>(floatCase));
			break;
		case 5:
			doubleCase = strtod(str, NULL);
			writeNumber(static_cast<int>(doubleCase), static_cast<float>(doubleCase), doubleCase);
			break;
	}
}

static int findType(const char *str)
{
	if (!strcmp(str, "-inff") || !strcmp(str, "+inff") || !strcmp(str, "nanf"))
		return 0;
	if (!strcmp(str, "-inf") || !strcmp(str, "+inf") || !strcmp(str, "nan"))
		return 1;
	if (strlen(str) == 1 && !isdigit(static_cast<char>(str[0]))) //entra si el primer caracter no es un digito
		return 2;

	char *endPtr;
	long number = strtol(str, &endPtr, 10);
	if (!*endPtr && number <= INT_MAX && number >= INT_MIN)
		return 3;
	
	strtod(str, &endPtr);
	if (!*endPtr)
		return 4;
	if (!strcmp(endPtr, "f"))
		return 5;
	
	return -1;
}

void ScalarConverter::convert(char *str)
{
	int type = findType(str);

	if (type == 0)
		floatSpecialCase(str);
	else if (type == 1)
		doubleSpecialCase(str);
	else if (type >= 2 && type <= 5)
		selectWriter(str, type);
	else
		std::cerr << "impossible to convert" << std::endl;
	
}
