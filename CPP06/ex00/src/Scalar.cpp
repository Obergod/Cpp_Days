/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:12:13 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/20 22:29:32 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

Scalar::Scalar()
{
	std::cout << "Scalar default constructor called" << std::endl;
}

Scalar::Scalar( const Scalar &other )
{
	std::cout << "Scalar copy constructor called" << std::endl;
}	

Scalar &Scalar::operator=( const Scalar &other )
{
	std::cout << "Scalar assignement operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

Scalar::~Scalar()
{
	std::cout << "Scalar default destructor called" << std::endl;
}

void	Scalar::convert( std::string &s )
{
	if (isChar(s))
		outputAsChar(s);
	else if (isInt(s))
		outputAsInt(s);
	else if (isFloat(s))
		outputAsFloat(s);
	else if (isDouble(s))
		outputAsDouble(s);
	else if (isNan(s))
		outputAsNan();
	else
	{
		std::cout << "Error: not printable" << std::endl;
	}
}
