/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:51:55 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/11 18:20:04 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Setters
void	Contact::set_first_name(std::string str)
{
	first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	last_name = str;
}

void	Contact::set_nickname(std::string str)
{
	nickname = str;
}

void	Contact::set_number(std::string str)
{
	number = str;
}

void	Contact::set_secret(std::string str)
{
	secret = str;
}

//Getters
std::string	Contact::get_first_name()
{
	return first_name;
}

std::string	Contact::get_last_name()
{
	return last_name;
}

std::string	Contact::get_nickname()
{
	return nickname;
}

std::string	Contact::get_number()
{
	return number;
}

std::string	Contact::get_secret()
{
	return secret;
}
