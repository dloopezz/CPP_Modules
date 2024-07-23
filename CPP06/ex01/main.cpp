/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:32:13 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/23 15:42:13 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data a;
	std::cout << "Data address: " << &a << std::endl;

	uintptr_t ptr = Serializer::serialize(&a);
	std::cout << "Serialized data address: " << ptr << std::endl;

	Data* b = Serializer::deserialize(ptr);
	std::cout << "Deserialized data address: " << b << std::endl;
	
	return 0;
}
