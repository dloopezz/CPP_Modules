/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:28:24 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/31 11:55:46 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

// void	leaks(void)
// {
// 	system("leaks Brain");
// }
// atexit(leaks);

int main()
{
	Animal *Animals[6];

	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}
	for (int j = 0; j < 6; j++)
	{
		delete Animals[j];
	}

	
	Dog *dog = new Dog();
	Brain *dogBrain = dog->getBrain();
	dogBrain->setIdea("guau", 1);
	std::cout << dogBrain->getIdea(1) << std::endl;
	std::cout << dogBrain->getIdea(42) << std::endl;
	std::cout << dogBrain->getIdea(100) << std::endl;
	delete dog;

	return 0;
}
