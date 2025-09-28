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
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Fixed Default Constructor Called" << std::endl;
#endif
}

Fixed::Fixed( const int i): _fix(i << _store)
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Fixed Int Constructor Called" << std::endl;
#endif
}

Fixed::Fixed (const float f ): _fix(roundf(f * (1 << _store)))
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Fixed Float Constructor Called" << std::endl;
#endif
}

Fixed::Fixed( const Fixed &other ): _fix( other._fix )
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Fixed copy Constructor Called" << std::endl;
#endif
}

Fixed	&Fixed::operator=( const Fixed &other )
{
	if (this != &other)
		this->_fix = other._fix;
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Fixed Copy Assignment Operator Called" << std::endl;
#endif
	return (*this);
}

Fixed	&Fixed::operator++()
{
	_fix++;
	return (*this);
}


Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	_fix++;
	return (tmp);
}

Fixed	&Fixed::operator--()
{
	_fix--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	_fix--;
	return (tmp);
}

Fixed	Fixed::operator+( const Fixed &other ) const
{
	Fixed	res;

	res._fix = this->_fix + other._fix;
	return res;
}

Fixed	Fixed::operator-( const Fixed &other ) const
{
	Fixed	res;

	res._fix = this->_fix - other._fix;
	return res;
}

Fixed	Fixed::operator*( const Fixed &other ) const 
{
	Fixed	res;

	res._fix = (this->_fix * other._fix) >> _store;
	return res;
}

Fixed	Fixed::operator/( const Fixed &other ) const 
{
	Fixed	res;

	res._fix = (this->_fix << _store) / other._fix;
	return res;
}

bool	Fixed::operator>( const Fixed &other ) const
{
	return this->_fix > other._fix;
}

bool	Fixed::operator<( const Fixed &other ) const
{
	return this->_fix < other._fix;
}

bool	Fixed::operator>=( const Fixed &other ) const
{
	return this->_fix >= other._fix;
}

bool	Fixed::operator<=( const Fixed &other ) const
{
	return this->_fix <= other._fix;
}

bool	Fixed::operator==( const Fixed &other ) const
{
	return this->_fix == other._fix;
}

bool	Fixed::operator!=( const Fixed &other ) const
{
	return this->_fix != other._fix;
}

Fixed::~Fixed()
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Fixed Default Destructor Called" << std::endl;
#endif
}

int	Fixed::getRawBits() const
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "getRawBits member function called" << std::endl;
#endif
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

Fixed	&Fixed::min( Fixed &a, Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed const	&Fixed::min( const Fixed &a, const Fixed &b)
{
	return (a < b) ? a : b;
}

Fixed	&Fixed::max( Fixed &a, Fixed &b)
{
	return (a > b) ? a : b;
}

Fixed const	&Fixed::max( const Fixed &a, const Fixed &b)
{
	return (a > b) ? a : b;
}
