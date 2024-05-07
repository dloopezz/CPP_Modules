/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 00:50:15 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/07 16:13:15 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
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

bool	all_of(const std::string& s, int (*func)(int));
int		stoi(const std::string& s);

# endif