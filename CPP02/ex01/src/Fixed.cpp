/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:43:55 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/24 20:43:56 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fix(0)
{
	std::cout << "Fixed Default Constructor Called" << std::endl;
}

Fixed::Fixed( const Fixed &other ): _fix( other._fix )
{
	std::cout << "Fixed copy Constructor Called" << std::endl;
}

Fixed	&Fixed::operator=( const Fixed &other )
{
	if (this != &other)
		this->_fix = other._fix;
	std::cout << "Fixed Copy Assignment Operator Called" << std::endl;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed Default Destructor Called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fix);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fix = raw;
}
