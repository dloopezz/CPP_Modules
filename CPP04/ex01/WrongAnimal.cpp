/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/29 17:35:41 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "\e[0;33mWrongAnimal: Default Constructor called\e[0m" << std::endl;
	type = "No Type";
	return ;	
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "\e[0;33mWrongAnimal: Copy Constructor called\e[0m" << std::endl;
	*this = copy;
	return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "\e[0;33mWrongAnimal: Destructor called\e[0m" << std::endl;
	return ;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "No sound, type not especified for WrongAnimal" << std::endl;
}