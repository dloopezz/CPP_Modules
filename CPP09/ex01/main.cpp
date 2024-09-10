/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopezz <lopezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:41:35 by lopezz            #+#    #+#             */
/*   Updated: 2024/09/07 13:21:50 by lopezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Invalid number of args" << std::endl;
		return 1;
	}

	try {
		RPN::exec(argv[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}
