/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:43:39 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/11 18:20:29 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string number;
		std::string secret;

	public:
		// Setters
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nickname(std::string str);
		void		set_number(std::string str);
		void		set_secret(std::string str);
		// Getters
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nickname();
		std::string	get_number();
		std::string	get_secret();
};

# endif