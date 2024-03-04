/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:44:17 by lopezz            #+#    #+#             */
/*   Updated: 2024/02/15 15:10:42 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon		weapon;
	public:
		HumanA(std::string name, std::string type);
		~HumanA(void);
		void	setName(std::string name);
		void	attack();
};

#endif