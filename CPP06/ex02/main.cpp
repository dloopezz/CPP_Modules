/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:53:10 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/26 12:05:05 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Base *generate(void)
{
	switch (rand() % 3) //puede tener un resultado de 0, 1 o 2, porque esos son los posibles restos de la división por 3
	{
		case (0):
			return new A();
		case (1):
			return new B();
		case (2):
			return new C();
	}
	return NULL;	
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Pointer Type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Pointer Type: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Pointer Type: C" << std::endl;
	else
		std::cout << "Unable to identify pointer type" << std::endl;
		
}

void identify(Base &p)
{
	try {
		(void)dynamic_cast< A &>(p);
		std::cout << "Reference Type: A" << std::endl;
		return ;
	}
	catch (const std::exception & e) {}
	
	try {
		(void)dynamic_cast< B &>(p);
		std::cout << "Reference Type: B" << std::endl;
		return ;
	}
	catch (const std::exception & e) {}
	
	try {
		(void)dynamic_cast< C &>(p);
		std::cout << "Reference Type: C" << std::endl;
		return ;
	}
	catch (const std::exception & e) {}

	std::cout << "Unable to identify reference type" << std::endl;
}

int main()
{
	srand(time(NULL));

	Base *aux = generate();
	identify(aux);
	identify(*aux);
	delete aux;
	
	Base  *aux2 = new Base();
	identify(aux2);
	identify(*aux2);
	delete aux2;
	
	return 0;
}
