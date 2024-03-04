/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:37:25 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/15 14:26:18 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce();
		void	nameZombie(std::string name);
};

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int n, std::string name);

# endif