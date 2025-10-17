/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:43:38 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/17 17:07:56 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"
#include "dog.hpp"
#include "wrongCat.hpp"
#include "brain.hpp"

int main()
{
	std::cout << "=== constructor ===" << std::endl;
	const Animal	*animals[6];

	for	(int i = 0; i < 6; i++)
	{
		if (i < 3)
			animals[i] = new Dog();
		if (i >= 3)
			animals[i] = new Cat();
		switch (i)
		{
			case (0):
				animals[i]->setIdea(i, "1");
				break;
			case (1):
				animals[i]->setIdea(i, "2");
				break;
			case (2):
				animals[i]->setIdea(i, "3");
				break;
			case (3):
				animals[i]->setIdea(i, "4");
				break;
			case (4):
				animals[i]->setIdea(i, "5");
				break;
			case (5):
				animals[i]->setIdea(i, "6");
				break;
		}
	}
	std::cout << std::endl;
	for	(int i = 0; i < 6; i++)
	{
		std::cout << "Type is : " <<  animals[i]->getType() << std::endl;
		animals[i]->makeSound();
		std::cout << "idea is : " <<  animals[i]->getIdea(i) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl << "=== Destructor === " << std::endl;
	for	(int i = 0; i < 6; i++)
		delete animals[i];

	return 0;
}
