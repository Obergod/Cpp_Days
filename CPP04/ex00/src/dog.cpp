/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:26:55 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/30 19:26:56 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog( const Dog &other ) : Animal()
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=( const Dog &other )
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Dog assignement operator called" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Default destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "*BARK*" << std::endl;
}


