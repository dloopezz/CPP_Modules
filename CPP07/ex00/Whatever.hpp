/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:28:29 by lopezz            #+#    #+#             */
/*   Updated: 2024/07/23 19:09:26 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
	T aux = a;
	a = b;
	b = aux;
}

template <typename T>
T min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T>
T max (T a, T b)
{
	return (a > b ? a : b);
}

#endif
