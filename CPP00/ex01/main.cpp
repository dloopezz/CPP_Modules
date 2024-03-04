/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:16:03 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/13 19:24:53 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;
	int			i = 0;
	
	phonebook.initialize();
	std::cout << std::endl << "\033[0;93mWelcome to your awesome Phonebook!\033[1;0m" << std::endl << std::endl;
	while (input != "EXIT")
	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "\033[3mADD: adds a contact" << std::endl;
		std::cout << "SEARCH: searchs a contact" << std::endl;
		std::cout << "EXIT: exits the Phonebook\033[1;0m" << std::endl ;
		std::cout << "---------------------------" << std::endl;
		std::cout << "Select an option: ";
		std::cin >> input;
		if (std::cin.eof())
			exit (1);
		if (input == "ADD")
		{
			phonebook.add_contact(i % 8);
			i++;	
		}
		else if (input == "SEARCH")
		{
			
			phonebook.search_contact();
		}
		else if (input == "EXIT")
			break;
		else
			std::cout << "\033[31mInvalid option\033[1;0m" << std::endl << std::endl;
	}
	std::cout << std::endl << "You exited Phonebook!" << std::endl;
	return (0);
}
