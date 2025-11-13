/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 20:29:06 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/13 20:32:48 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: Bad argument count" << std::endl;
		return (1);
	}

	try
	{
		Rpn	rpn;
	
		std::stringstream ss(av[1]);

		rpn.mainLoop(ss);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
