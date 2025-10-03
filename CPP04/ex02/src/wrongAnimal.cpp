/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:51:41 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/30 20:51:42 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("")
{
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &other ) : _type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &other )
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "WrongAnimal assignement operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Default destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "*Weird Uncomprehensible growling*" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return _type;
}

