/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 18:17:47 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/22 18:17:47 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string	replace_all(const std::string &line, const std::string &from, const std::string &to)
{
	if (from.empty())
		return (line);
		

	std::string n_line = line;
	size_t		pos = 0;

	while ((pos = n_line.find(from, pos)) != std::string::npos)
	{
		n_line.erase(pos, from.length());
		n_line.insert(pos, to);
		pos += to.length();
	}
	return (n_line);
}

int	main(int ac, char **av)
{
	if (ac < 4)
		return (1);

	std::string		out_name = av[1];
	std::string		s1 = av[2];
	std::string		s2 = av[3];

	out_name += ".replace";
	std::ifstream	inFile(av[1]);
	std::ofstream	outFile(out_name.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "file does not exist" << std::endl;
		return (1);
	}
	if (!outFile.is_open())
	{
		std::cerr << "outfile error" << std::endl;
		return (1);
	}

	std::string	line;
	while (getline(inFile, line))
	{
		std::string	n_line = replace_all(line, s1, s2);
		outFile << n_line << std::endl;
	}

	return (0);
}
