/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:02:17 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/23 19:31:25 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void printElem (T &elem)
{
	std::cout << elem << std::endl;
}

template <typename T>
void plusOne(T &elem)
{
	elem += 1;
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t charArrayLen = sizeof(intArray) / sizeof(intArray[0]);
	iter(intArray, charArrayLen, printElem<int>);
	std::cout << std::endl;
	iter(intArray, charArrayLen, plusOne<int>);
	iter(intArray, charArrayLen, printElem<int>);
	std::cout << std::endl;
	
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t intArrayLen = sizeof(charArray) / sizeof(charArray[0]);
	iter(charArray, intArrayLen, printElem<char>);
	std::cout << std::endl;
	iter(charArray, intArrayLen, plusOne<char>);
	iter(charArray, intArrayLen, printElem<char>);

	return 0;
}
