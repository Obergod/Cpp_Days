/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:26:00 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/03 19:26:01 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "Amateria default constructor called" << std::endl;
}


AMateria::AMateria( const AMateria &other ): _type(other._type)
{
	std::cout << "Amateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=( const AMateria &other )
{
	std::cout << "Amateria assignement operator called" << std::endl;
	if (this != &other)
	{
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "Amateria default destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void	AMateria::use( ICharacter &target )
{
	std::cout << "How the hell did you manage to use this spell ??" << std::endl;
	std::cout << "What ever it is you use it on : " << target.getName() << std::endl;
}
