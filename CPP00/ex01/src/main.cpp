/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 17:50:25 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/08 17:50:26 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main()
{
	std::string line;

	while (1)
	{
		std::cout << "Enter command : ADD | SEARCH | EXIT" << std::endl;
		std::getline(std::cin, line);
		if (line == "EXIT")
			exit(0);

	}

}
