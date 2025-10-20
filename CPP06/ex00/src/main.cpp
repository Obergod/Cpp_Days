/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:29:00 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/20 20:56:08 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Number of arg not good" << std::endl;
		return (1);
	}

	std::string s = av[1];
	Scalar::convert(s);
}
