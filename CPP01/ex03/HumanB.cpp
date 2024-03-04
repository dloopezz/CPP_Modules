/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:48:09 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/14 19:07:38 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{
	return;
}

HumanB::~HumanB(void)
{
	return;
}

void	HumanB::attack()
{
	std::string	weaponType = weapon.getType();
	std::cout << name << "> attacks with their " << weaponType << std::endl;
}
