/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/29 17:22:28 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "\e[0;33mCat: Default Constructor called\e[0m" << std::endl;
	type = "Cat";
	return ;	
}

Cat::Cat(const Cat &copy) : Animal()
{
	std::cout << "\e[0;33mCat: Copy Constructor called\e[0m" << std::endl;
	*this = copy;
	return ;
}

Cat &Cat::operator=(const Cat &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "\e[0;33mCat: Destructor called\e[0m" << std::endl;
	return ;
}

void Cat::makeSound() const
{
	std::cout << "Miau miau" << std::endl;
}