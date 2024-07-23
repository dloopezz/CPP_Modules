/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:45:47 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/23 20:31:35 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template <typename T>
class Array
{
	private:
		T *array;
		size_t arraySize;
	
	public:
		Array() : array(NULL), arraySize(0) {};
		
		Array(unsigned int n) : array(new T[n]), arraySize(n) {};
		
		Array (const Array &copy)
		{
			*this = copy;
		}
		
		Array &operator=(const Array &assign)
		{
			if (this != &assign)
			{
				this->arraySize = assign.arraySize;
				
				this->array = new T[arraySize];
				for (size_t i = 0; i < arraySize; i++)
					this->array[i] = assign.array[i];	
			}
			return *this;
		}

		~Array()
		{
			delete[] array;
		}

		T &operator[](size_t i)
		{
			if (i >= this->arraySize)
				throw std::out_of_range("Index is higher than array size");
			return this->array[i];
		}
		
		size_t size()
		{
			return this->arraySize;
		}
};

#endif