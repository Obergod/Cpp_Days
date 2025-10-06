/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:28:35 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/03 19:28:36 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice( const Ice &other ): AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice &Ice::operator=( const Ice &other )
{
	std::cout << "Ice assignement operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice default destructor called" << std::endl;
}

AMateria*	Ice::clone() const
{
	return new Ice();
}

void	Ice::use( ICharacter &target )
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
