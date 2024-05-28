/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:21:45 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/28 16:39:47 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap clap("Marvin");
	ScavTrap scav("Vinmar");

	clap.attack("Vinmar");
	scav.takeDamage(1);
	scav.beRepaired(2);
	scav.attack("Marvin");
	clap.takeDamage(11);
	clap.beRepaired(4);
	scav.guardGate();
	return 0;
}

