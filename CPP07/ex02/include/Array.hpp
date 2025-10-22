/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:24:26 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/22 20:52:22 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
# include <algorithm>

template <typename T>
class	Array
{
	private:
		T*	_array;
		unsigned int _size;
	public:
		Array();
		Array( unsigned int n );
		Array( const Array<T> &other );
		Array<T> &operator=( const Array<T> &other ) ;;
		T&	operator[](unsigned int index);
		~Array();

		unsigned int	size() const;

		class	OutOfBound: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#include "Array.tpp"













#endif
