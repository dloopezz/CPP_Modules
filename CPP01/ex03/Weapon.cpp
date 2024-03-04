/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:38:01 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/15 14:25:25 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return;
}

Weapon::Weapon(std::string type)
{
	setType(type);
	return;
}

Weapon::~Weapon(void)
{
	return;
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}

std::string	Weapon::getType()
{
	return (type);
}
