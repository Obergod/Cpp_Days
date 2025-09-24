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

class	Fixed
{
	private:
		int	_fix;
		static const int _store = 8;
	public:
		Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=( const Fixed &other );
		~Fixed();
		int		getRawBits() const;
		void	setRawBits( int const raw );

};

#endif
