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

int	main()
{
	std::ifstream	inFile("texasdasdt.txt");
	if (!inFile.is_open())
	{
		std::cout << "file does not exist" << std::endl;
		return (1);
	}
	return (0);
}
