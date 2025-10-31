/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:40:34 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/31 16:39:56 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>


class	Span
{
	private:
		size_t				_maxSize;
		std::vector<int>	_numbers;
	public:
		Span( unsigned int n );
		Span(const Span &other);
		Span &operator=( const Span &other );
		~Span();
		void	addNumber( int nb );
		void	addNumbers( std::vector<int> nbs );
		void	addNumbers( int *nbs );
		int		shortestSpan();
		int		longestSpan();
		

		class	TooManyException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	NoSpanException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};











#endif
