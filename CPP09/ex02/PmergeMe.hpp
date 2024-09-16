/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:43:50 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/12 16:46:30 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <string> 
#include <cmath>
#include <exception>
#include <vector>
#include <deque>
#include <sys/time.h>

class PMergeMe 
{
	private:
		std::vector<int> myVec;
		std::deque<int> myDeq;

	
	public:
		class inputErrorException : public std::exception {
			const char *what() const throw() {
				return "Error: bad input";
			}
		};
		
		PMergeMe(std::vector<int> input);
		PMergeMe(const PMergeMe &copy);
		PMergeMe &operator=(const PMergeMe &other);
		~PMergeMe();

		std::vector<int> &getVec();
		std::vector<int> vecAlgorithm();

		std::deque<int> &getDeq();
		void deqAlgorithm();
		void printDeq(std::deque<int> deq);
};

#endif