/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:43:50 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/10 21:06:35 by lopezz           ###   ########.fr       */
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

class PMergeMe 
{
	private:
		std::vector<int> myVec;
		std::deque<int> myDeq;
	
	public:
		PMergeMe(std::vector<int> input);
		PMergeMe(const PMergeMe &copy);
		PMergeMe &operator=(const PMergeMe &other);
		~PMergeMe();

		std::vector<int> &getVec();
		void vecAlgorithm();
};

#endif