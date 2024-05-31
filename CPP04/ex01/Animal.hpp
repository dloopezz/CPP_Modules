/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:02:27 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/31 11:55:46 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
# define Animal_HPP

#include "iostream"
#include "string"

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal &copy);
		Animal & operator=(const Animal &assign);

		virtual ~Animal();

		std::string getType() const;
		virtual void makeSound() const;
};

#endif