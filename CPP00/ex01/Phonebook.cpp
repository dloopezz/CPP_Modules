/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:58:45 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/13 14:47:14 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

void	Phonebook::initialize()
{
	n_contacts = 0;
}

void	Phonebook::add_contact(int i)
{
	std::string input;

	std::cout << std::endl << "\033[0;93mAdding contact...\033[1;0m" << std::endl << std::endl;
	std::cout << "First Name: ";
	std::cin.ignore();
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit (1);
	contact[i].set_first_name(input);

	std::cout << "Last Name: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit (1);
	contact[i].set_last_name(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit (1);
	contact[i].set_nickname(input);

	std::cout << "Number: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit (1);
	contact[i].set_number(input);

	std::cout << "Darkest Secret: ";
	std::getline(std::cin, input);
	if (std::cin.eof())
		exit (1);
	contact[i].set_secret(input);

	std::cout << std::endl;
	n_contacts++;
}

void	Phonebook::read_contact(int index)
{
	std::cout << "First Name: " << contact[index].get_first_name() << std::endl;
	std::cout << "Last Name: " << contact[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contact[index].get_nickname() << std::endl;
	std::cout << "Phone Number: " << contact[index].get_number() << std::endl;
	std::cout << "Darkest Secret: " << contact[index].get_secret() << std::endl;
	std::cout << std::endl;
}

void	Phonebook::print_data(std::string str)
{
	if (str.size() <= 10)
		std::cout << std::setw(10) << str << "|";
	else
		std::cout <<  str.substr(0, 9) << ".|";
}

void	Phonebook::search_contact()
{
	if (n_contacts > 8)
		n_contacts = 8;
	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 1; i <= n_contacts; i++)
	{
		std::cout << "|";
		std::cout << std::setw(10);
		std::cout << i;
		std::cout << "|";
		print_data(contact[i - 1].get_first_name());
		print_data(contact[i - 1].get_last_name());
		print_data(contact[i - 1].get_nickname());
		std::cout << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	std::cout << std::endl << "Index of the contact you want to access: ";
	std::string option;
	std::cin >> option;
	if (std::cin.eof())
		exit (1);

	if (std::all_of(option.begin(), option.end(), ::isdigit)) 
	{
    	int index = std::stoi(option);
		std::cout << std::endl << "\033[0;93mContact " << index << " selected!\033[1;0m" << std::endl;
		if (index < 1 || index > n_contacts)
	    	std::cout << "\033[31mContact doesn't exist.\033[1;0m" << std::endl << std::endl;
		else
			read_contact(index - 1);
	} 
	else 
	    std::cout << "\033[31mInvalid option\033[1;0m" << std::endl << std::endl;
}
