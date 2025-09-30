/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:26:49 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/30 19:26:50 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat( const Cat &other ) : Animal()
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=( const Cat &other )
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Cat assignement operator called" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Default destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "*MEOW*" << std::endl;
}

