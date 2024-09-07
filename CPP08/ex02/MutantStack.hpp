/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:07:51 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/06 17:44:56 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <algorithm>

template <typename T>
class MutantStack : public std::stack< T, std::deque<T> >
{
	public:
		MutantStack(): std::stack< T, std::deque<T> >() {};
		
		MutantStack(const MutantStack &copy)
		{
			*this = copy;
		};
		MutantStack &operator=(const MutantStack &assign)
		{
			//aaaaaaa
			return *this;
		};
		
		~MutantStack() {};

		typedef typename std::deque<T>::iterator iterator;
		iterator begin()
		{
			return this->c.begin();
		}
		iterator end()
		{
			return this->c.end();
		}
};

// template <typename T>
// class MutantStack : public std::stack< T, std::list<T> >
// {
// 	public:
// 		MutantStack(): std::stack< T, std::list<T> >() {};
		
// 		MutantStack(const MutantStack &copy)
// 		{
// 			*this = copy;
// 		};
// 		MutantStack &operator=(const MutantStack &assign)
// 		{
// 			if (this != &assign)
// 				*this = assign;		
// 			return *this;
// 		};
		
// 		~MutantStack() {};

// 		typedef typename std::list<T>::iterator iterator;
// 		iterator begin()
// 		{
// 			return this->c.begin();
// 		}
// 		iterator end()
// 		{
// 			return this->c.end();
// 		}
// };

#endif