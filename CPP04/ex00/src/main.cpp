/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:43:38 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/17 17:02:37 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"
#include "dog.hpp"
#include "wrongCat.hpp"

int main()
{
	std::cout << "=== constructor ===" << std::endl;
	const Animal* arnold = new Animal();
	const Animal* didier = new Dog();
	const Animal* charles = new Cat();
	const WrongAnimal* norald = new WrongAnimal();
	const WrongCat* arlche = new WrongCat();

	std::cout << std::endl << "Didier is a " << didier->getType() << " " << std::endl;
	std::cout <<  "charles is a " << charles->getType() << " " << std::endl;

	arnold->makeSound();
	didier->makeSound();
	charles->makeSound(); 
	norald->makeSound(); 
	arlche->makeSound(); 

	std::cout << std::endl << "=== Destructor === " << std::endl;
	delete arnold;
	delete didier;
	delete charles;
	delete norald;
	delete arlche;

	return 0;
}
