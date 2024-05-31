/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:07:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/29 17:22:28 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "\e[0;33mWrongCat: Default Constructor called\e[0m" << std::endl;
	type = "WrongCat";
	return ;	
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal()
{
	std::cout << "\e[0;33mWrongCat: Copy Constructor called\e[0m" << std::endl;
	*this = copy;
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "\e[0;33mWrongCat: Destructor called\e[0m" << std::endl;
	return ;
}

void WrongCat::makeSound() const
{
	std::cout << "aañañaññañ añaña añaaaaaa" << std::endl;
}