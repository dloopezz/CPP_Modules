/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:50:15 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/12 20:24:14 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "Contact.hpp"

class Phonebook
{
	private:
		Contact contact[8];
		int		n_contacts;
	public:
		void	initialize();
		void	add_contact(int i);
		void	search_contact();
		void	read_contact(int index);
		void	print_data(std::string str);
};

# endif