/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:21:45 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/28 16:11:17 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap marvin("Marvin");
	ClapTrap vinmar("Vinmar");

	marvin.attack("Vinmar");
	vinmar.takeDamage(1);
	vinmar.beRepaired(2);
	vinmar.attack("Marvin");
	marvin.takeDamage(11);
	marvin.beRepaired(4);
	
	return 0;
}

