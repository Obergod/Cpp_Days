/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:27:14 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/24 20:27:15 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Level missing" << std::endl;
		return (1);
	}

	Harl	harl;
	std::string	level = av[1];

	harl.complain(level);
}
