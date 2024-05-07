/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlopez-s <dlopez-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:38:23 by lopezz            #+#    #+#             */
/*   Updated: 2024/05/07 16:56:12 by dlopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 4)
	{
		std::string		to_replace = argv[2];
		if (to_replace.length() == 0)
			return (std::cout << "empty string" << std::endl, 0);
		std::string		replacement = argv[3];
		std::ifstream 	infile(argv[1]);
		
		if (infile.is_open())
		{
			std::string line;
			std::ofstream outfile((std::string(argv[1]) + ".replace").c_str());
			while (std::getline(infile, line))
            {
                size_t pos = 0;
                while ((pos = line.find(to_replace, pos)) != std::string::npos)
                {
                    line.erase(pos, to_replace.length());
                    line.insert(pos, replacement);
                    pos += replacement.length();
                }
                outfile << line << std::endl;
            }
			outfile.close();
			infile.close();
		}
		else
			std::cout << "error opening file" << std::endl;
	}
	else
		std::cout << "invalid arguments" << std::endl;
	return 0;
}
