/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:42:25 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/12 17:16:39 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> createVec(int argc, char **argv)
{
	std::vector<int> auxVec;

	for (int i = 1; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
    	int num;
    	ss >> num;
    	if (num < 0 || ss.fail())
			throw PMergeMe::inputErrorException();
			
		auxVec.push_back(num);
	}
	return auxVec;
}

void printVec(std::vector<int> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl << std::endl;
}

void printTime(int start, int end, int argc, std::string container)
{
    std::cout << "Time to process a range of " << argc - 1 << " elements with " << container << ": ";
    std::cout << (end - start)/double(CLOCKS_PER_SEC)*1000;
    std::cout << " us" << std::endl;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Invalid arguments" << std::endl;
		return 1;
	}

	try {
		std::vector<int> input = createVec(argc, argv);

		std::cout << "Before: ";
		printVec(input); 

		PMergeMe a(input);

		int vecStart = clock() ; 
		input = a.vecAlgorithm();
	    int vecEnd = clock();

		int deqStart = clock() ; 
		a.deqAlgorithm();
	    int deqEnd = clock(); 
		
		std::cout << "After: ";
		printVec(input);

		printTime(vecStart,vecEnd, argc, "std::vector");
    	printTime(deqStart,deqEnd, argc, "std::deque");
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	
	return 0;
}

//TODO
////1. quitar swap, no me gusta, cambiarlo por un return o algo así
//// 2. checkear necesidad if l.86
////3. print sorted
////4. hacer todo para deque
////5. buen main y error handling
////6. timestamps
//7. operator= bien??