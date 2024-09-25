/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 20:29:49 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/25 16:21:47 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Array.hpp"

int main( void )
{
	srand(static_cast<unsigned int>(time(0)));
	{
		/* OCCF and empty array test */
		Array<int> a;
		Array<int> b( 10 );
		Array<int> c = a;
		Array<int> d;
		d = b;

		std::cout << "A - address: "<< &a << " size: " << a.size() << '\n';
		std::cout << "B - address: "<< &b << " size: " << b.size() << '\n';
		std::cout << "C - address: "<< &c << " size: " << c.size() << '\n';
		std::cout << "D - address: "<< &d << " size: " << d.size() << '\n';
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* Fill array test */
		int n = 5;
		Array<int> a(n);

		for (int i = 0; i < n; i++) {
			int random = rand();
			a[i] = random;
		}

		for (int i = 0; i < n; i++) {
			std::cout << a[i] << '\n';
		}
	}
	std::cout << "----------------------------------------------------\n";
	{
		/* Invalid index management test */
		try {
			int n = 5;
			Array<int> a(n);

			for (int i = 0; i < n; i++) {
				int random = rand();
				a[i] = random;
			}

			// access to invalid index -1:
			a[-1] = 10;

			for (int i = 0; i < n; i++) {
			std::cout << a[i] << '\n';
			}
			
		} catch (std::exception& e) {
			std::cout << e.what() << '\n';
		}
	}

	return 0;
}