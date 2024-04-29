/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:48:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/04/29 19:20:59 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): name(name), weapon()
{
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
//ahora el miembro weapon del objeto HumanB apunta al objeto Weapon pasado como argumento

void	HumanB::attack()
{
	if (this->weapon)
	{
		std::string	weaponType = weapon->getType();
		std::cout << name << " attacks with their " << weaponType << std::endl;
	}
}
