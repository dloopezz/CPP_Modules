/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:46:37 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/28 16:36:29 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;	
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return ;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "\e[0;33mName Constructor called of FragTrap\e[0m" << std::endl;	
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	return ;
}

//Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << std::endl;
	return ;
}

//Other:
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap is so happy that he wants to high five with you! :)" << std::endl;
	return ;
}
