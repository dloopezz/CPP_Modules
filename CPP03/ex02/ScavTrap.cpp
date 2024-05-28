/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:46:37 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/28 16:16:43 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors
ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;	
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "\e[0;33mName Constructor called of ScavTrap\e[0m" << std::endl;	
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	return ;
}

//Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << std::endl;
	return ;
}

//Other:
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gatekeeper mode" << std::endl;
	return ;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints <= 0)
	{
		std::cout <<  "ScavTrap " << this->name << " is dead, it can't attack!" << std::endl;
		return ;
	}
	if (this->energyPoints <= 0)
	{
		std::cout <<  "ScavTrap " << this->name << " has no energy left" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints--;
	return ;
}
