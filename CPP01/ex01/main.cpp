/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:23:31 by lopezz            #+#    #+#             */
/*   Updated: 2024/03/06 16:16:35 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *horde;

	horde = zombieHorde(33, "Viti");
	delete[] horde;
	return 0;
}

/* `delete[] horde;` is deleting the dynamically allocated array of Zombie objects.
It is important to use `delete[]` instead of `delete` when deleting an array, as
`delete[]` ensures that the memory for all elements in the array is properly
deallocated. */