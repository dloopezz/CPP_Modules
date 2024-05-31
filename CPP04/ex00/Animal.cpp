/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/31 11:55:46 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "\e[0;33mAnimal: Default Constructor called\e[0m" << std::endl;
	type = "No Type";
	return ;	
}

Animal::Animal(const Animal &copy)
{
	std::cout << "\e[0;33mAnimal: Copy Constructor called\e[0m" << std::endl;
	*this = copy;
	return ;
}

Animal &Animal::operator=(const Animal &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "\e[0;33mAnimal: Destructor called\e[0m" << std::endl;
	return ;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "No sound, type not especified" << std::endl;
}