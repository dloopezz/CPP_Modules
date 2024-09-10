/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:42:25 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/10 21:05:37 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int stringToInt(const std::string& str) {
    std::stringstream ss(str);
    int num;
    ss >> num;
    if (ss.fail()) {
        // Manejo de error si la conversión falla
        std::cerr << "Error: La conversión de string a int falló." << std::endl;
        return 0; // O cualquier valor por defecto o manejo de error
    }
    return num;
}

std::vector<int> createVec(int argc, char **argv)
{
	std::vector<int> auxVec;

	for (int i = 1; i < argc; i++)
	{
		int n = stringToInt(argv[i]); //hacer conversion directamente sin otra funcion
		//handle negative
		auxVec.push_back(n);
	}
	return auxVec;
}

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "Que coño haces" <<std::endl;

	std::vector<int> input = createVec(argc, argv);
	PMergeMe a(input);

	a.vecAlgorithm();
	
	return 0;
}
