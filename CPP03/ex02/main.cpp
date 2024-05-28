/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:21:45 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/28 16:38:55 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap clap("Marvin");
	FragTrap frag("Vinmar");

	clap.attack("Vinmar");
	frag.takeDamage(1);
	frag.beRepaired(2);
	frag.attack("Marvin");
	clap.takeDamage(11);
	clap.beRepaired(4);
	frag.highFivesGuys();

	return 0;
}

