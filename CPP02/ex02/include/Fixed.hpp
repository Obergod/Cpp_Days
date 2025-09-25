/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:44:25 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/24 20:44:27 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class	Fixed
{
	private:
		int	_fix;
		static const int _store = 8;
	public:
		Fixed();
		Fixed( const int i );
		Fixed( const float f);
		Fixed(const Fixed &other);
		Fixed	&operator=( const Fixed &other );
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);
		Fixed	operator+( const Fixed &other ) const;
		Fixed	operator-( const Fixed &other ) const;
		Fixed	operator*( const Fixed &other ) const;
		Fixed	operator/( const Fixed &other ) const;
		bool	operator>( const Fixed &other ) const;
		bool	operator<( const Fixed &other ) const;
		bool	operator>=( const Fixed &other ) const;
		bool	operator<=( const Fixed &other ) const;
		bool	operator==( const Fixed &other ) const;
		bool	operator!=( const Fixed &other ) const;
		~Fixed();
		int		getRawBits() const;
		void	setRawBits( int const raw );
		float	toFloat() const;
		int		toInt() const;
		static Fixed	&min(Fixed &a, Fixed &b);
		static Fixed const	&min(const Fixed &a, const Fixed &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static Fixed const	&max(const Fixed &a, const Fixed &b);
		
	friend std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

};

#endif
