/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:01:14 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/12 22:06:32 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	try
	{
		BtcExchange btc;

		btc.fillRate(av[1]);
		btc.loadDatabase("data.csv");
		
		btc.printBtcRate();
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
