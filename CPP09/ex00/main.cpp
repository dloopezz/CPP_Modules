/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:55:25 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/04 19:12:07 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try {
			BitcoinExchange btc;
			btc.calcExchange(argv[1]);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			return 1;
		}
	}
	else
	{
		std::cerr << "Invalid number of args." << std::endl;
		return 1;
	}

	return 0;
}
