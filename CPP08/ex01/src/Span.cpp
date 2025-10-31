/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:51:22 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/31 18:11:56 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int n ) : _maxSize(n)
{
	std::cout << "Span default constructor called" << std::endl;
}

Span::Span( const Span &other ) : _maxSize(other._maxSize)
{
	std::cout << "Span copy constructor called" << std::endl;
}	

Span &Span::operator=( const Span &other )
{
	std::cout << "Span assignement operator called" << std::endl;
	if (this != &other)
	{
		_maxSize = other._maxSize;
	}
	return *this;
}

Span::~Span()
{
	std::cout << "Span default destructor called" << std::endl;
}

const char	*Span::TooManyException::what() const throw()
{
	return "Exception: Max size reached";
}

const char	*Span::NoSpanException::what() const throw()
{
	return "Exception: Not enough numbers to have a span";
}

void	Span::addNumber( int nb )
{
	if (_numbers.size() == _maxSize)
		throw TooManyException();
	_numbers.push_back(nb);
}


int		Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end(), std::greater<int>());
	std::vector<int>::iterator it = tmp.begin();

	int res = *it - *(it + 1);
	while (it + 1 != tmp.end())
	{
		int min = *it - *(it + 1);
		if (min < res)
			res = min;
		it++;
	}
	return res;
}

int		Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int>::iterator min = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::iterator max = std::max_element(_numbers.begin(), _numbers.end());

	return (*max - *min);
}

void	Span::addNumbers( std::vector<int> nbs )
{
	for (std::vector<int>::iterator it = nbs.begin();
			it != nbs.end(); it++)
	{
		if (_numbers.size() == _maxSize)
			throw TooManyException();
		_numbers.push_back(*it);
	}
}









