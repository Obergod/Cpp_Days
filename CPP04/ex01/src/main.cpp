/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:43:38 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/30 20:43:39 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"
#include "dog.hpp"
#include "wrongCat.hpp"

int main()
{
	const Animal	*animals[6];

	for	(int i = 0; i < 6; i++)
	{
		if (i < 3)
			animals[i] = new Dog();
		if (i >= 3)
			animals[i] = new Cat();
	}
	std::cout << std::endl;
	for	(int i = 0; i < 6; i++)
	{
		std::cout << "Type is : " <<  animals[i]->getType() << std::endl;
		animals[i]->makeSound();
	}
	std::cout << std::endl;
	for	(int i = 0; i < 6; i++)
		delete animals[i];

	return 0;
}
