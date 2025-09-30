/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:26:35 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/30 19:26:38 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal() : _type("")
{
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal( const Animal &other ) : _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=( const Animal &other )
{
	if (this != &other)
	{
		_type = other._type;
	}
	std::cout << "Animal assignement operator called" << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal Default destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "*Uncomprehensible growling*" << std::endl;
}

std::string	Animal::getType() const
{
	return _type;
}
