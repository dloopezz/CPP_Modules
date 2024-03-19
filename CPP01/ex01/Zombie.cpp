/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:41:51 by lopezz            #+#    #+#             */
/*   Updated: 2024/03/06 16:08:52 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	return ;
}

Zombie::Zombie(std::string name)
{
	this->name = name; 
	announce();
	return ;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << name << " went to sleep..." << std::endl;
	return ;
}

void	Zombie::nameZombie(std::string name)
{
	this->name = name;
	announce();
	return ;
}

void	Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
