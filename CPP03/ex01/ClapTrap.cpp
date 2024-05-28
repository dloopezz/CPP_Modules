/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:37:08 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/28 15:58:11 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ClapTrap\e[0m" << std::endl;
	name = "Bot";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ClapTrap\e[0m" << std::endl;	
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return ;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "\e[0;33mName Constructor called of ClapTrap\e[0m" << std::endl;	
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	return ;
}

//Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor called of ClapTrap\e[0m" << std::endl;
	return ;
}

// Operators
ClapTrap &ClapTrap::operator=(const ClapTrap &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
	{
		this->name = assign.name;
		this->hitPoints = assign.hitPoints;
		this->energyPoints = assign.energyPoints;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}

//Other
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout <<  "ClapTrap " << this->name << " is dead, it can't receive damage!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " received " << amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
	if (this->hitPoints <= 0)
	{
		std::cout <<  "ClapTrap " << this->name << " died after receiving that damage :(" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout <<  "ClapTrap " << this->name << " is dead, it can't be repaired!" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout <<  "ClapTrap " << this->name << " has no energy left" << std::endl;
		return ;
	}
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " repaired itself, getting " << amount << "HP back. It's now at " << this->hitPoints << "HP" << std::endl;
	this->energyPoints--;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0)
	{
		std::cout <<  "ClapTrap " << this->name << " is dead, it can't attack!" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout <<  "ClapTrap " << this->name << " has no energy left" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
	return ;
}