/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:30:14 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/30 18:36:22 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int	main()
{
	std::vector<int>	vec1;
	std::vector<int>	vec2;

	vec1.push_back(1);
	vec1.push_back(2);
	vec1.push_back(3);
	vec1.push_back(2);

	vec2.push_back(4);

	std::vector<int>::iterator res1 = easyfind(vec1, 2);
	int	pos1 = std::distance(vec1.begin(), res1);
	if (res1 != vec1.end())
		std::cout << "found at pos: " << pos1 << std::endl;
	else
		std::cout << "not found"<< std::endl;

	std::vector<int>::iterator res2 = easyfind(vec2, 2);
	int	pos2 = std::distance(vec2.begin(), res2);
	if (res2 != vec2.end())
		std::cout << "found at pos: " << pos1 << std::endl;
	else
		std::cout << "not found"<< std::endl;

}
