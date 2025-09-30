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
	const Animal* arnold = new Animal();
	const Animal* didier = new Dog();
	const Animal* charles = new Cat();
	const WrongAnimal* norald = new WrongAnimal();
	const WrongCat* arlche = new WrongCat();

	std::cout << didier->getType() << " " << std::endl;
	std::cout << charles->getType() << " " << std::endl;

	arnold->makeSound();
	didier->makeSound();
	charles->makeSound(); 
	norald->makeSound(); 
	arlche->makeSound(); 

	delete arnold;
	delete didier;
	delete charles;
	delete norald;
	delete arlche;

	return 0;
}
