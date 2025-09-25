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

Fixed::Fixed( const int i): _fix(i << _store)
{
	std::cout << "Fixed Int Constructor Called" << std::endl;
}

Fixed::Fixed (const float f ): _fix(roundf(f * (1 << _store)))
{
	std::cout << "Fixed Float Constructor Called" << std::endl;
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

float	Fixed::toFloat() const
{
	return static_cast<float>(_fix) / (1 << _store);
}

int	Fixed::toInt() const
{
	return _fix >> _store;
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}
