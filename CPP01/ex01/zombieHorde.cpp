/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:43:33 by lopezz            #+#    #+#             */
/*   Updated: 2024/03/06 16:04:17 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int n, std::string name)
{	
	Zombie *zombieHorde = new Zombie[n];

	for (int i = 0; i < n; i++)
		zombieHorde[i].nameZombie(name);
	return (zombieHorde);
}
