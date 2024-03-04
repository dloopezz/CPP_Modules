/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:48:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/17 18:09:21 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, std::string type)
{
	setName(name);
	weapon.setType(type);
	return;
}

HumanA::~HumanA(void)
{
	return;
}

void	HumanA::setName(std::string name)
{
	this->name = name;
}

void	HumanA::attack()
{
	std::string	weaponType = weapon.getType();
	std::cout << name << "> attacks with their " << weaponType << std::endl;
}
