/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 19:33:00 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/04 16:13:39 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _array(NULL), _size(0)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array( unsigned int n ): _array(new T[n]), _size(n)
{
    std::cout << "Array default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array( const Array<T> &other ): _array(NULL), _size(other._size)
{
    std::cout << "Array copy constructor called" << std::endl;
	if (other._size)
	{
		_array = new T[_size];
		std::copy(other._array, other._array + _size, _array);
	}
}   

template <typename T>
Array<T> &Array<T>::operator=( const Array<T> &other ) 
{
    std::cout << "Array assignement operator called" << std::endl;
    if (this != &other)
    {
		delete[] _array;
		_size = other._size;

		if (_size)
		{
			_array = new T[_size];
			std::copy(other._array, other._array + _size, _array);
		}
		else
			_array = NULL;
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    std::cout << "Array default destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
const char	*Array<T>::OutOfBound::what() const throw()
{
	return "Out of bound index";
}

template <typename T>
unsigned int	Array<T>::size() const
{
	return _size;
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBound();
	return _array[index];
}
