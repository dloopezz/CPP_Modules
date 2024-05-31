/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/29 17:22:28 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "\e[0;33mDog: Default Constructor called\e[0m" << std::endl;
	type = "Dog";
	this->brain = new Brain();
	return ;	
}

Dog::Dog(const Dog &copy) : Animal()
{
	std::cout << "\e[0;33mDog: Copy Constructor called\e[0m" << std::endl;
	*this = copy;
	return ;
}

Dog &Dog::operator=(const Dog &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
	{
		this->type = assign.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain();
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "\e[0;33mDog: Destructor called\e[0m" << std::endl;
	delete this->brain;
	return ;
}

void Dog::makeSound() const
{
	std::cout << "Guau guau" << std::endl;
}

Brain *Dog::getBrain()
{
	return this->brain;
}