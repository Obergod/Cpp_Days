/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 19:26:34 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/14 19:33:18 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Not enough arguments" << std::endl;
		return (1);
	}

	try
	{
		Pmerge merge;

		merge.parseInput(ac, av);

		merge.sort();
	}
	
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
