/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:28:54 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/03 19:28:54 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure( const Cure &other ): AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure &Cure::operator=( const Cure &other )
{
	std::cout << "Cure assignement operator called" << std::endl;
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure default destructor called" << std::endl;
}

AMateria*	Cure::clone() const
{
	return new Cure();
}

void	Cure::use( ICharacter &target )
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

