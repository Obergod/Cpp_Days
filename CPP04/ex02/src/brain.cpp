/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:16:56 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/01 17:17:00 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"
# include <algorithm>

Brain::Brain() 
{
	std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain( const Brain &other ) 
{
	std::copy(other._ideas, other._ideas + 100, _ideas);

	std::cout << "Brain copy constructor called" << std::endl;
}

Brain	&Brain::operator=( const Brain &other )
{
	if (this != &other)
	{
		std::copy(other._ideas, other._ideas + 100, _ideas);
	}
	std::cout << "Brain assignement operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain Default destructor called" << std::endl;
}

void	Brain::setIdea( int i, const std::string &idea)
{
	if (i >= 0 && i < 100)
		_ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return _ideas[i];
	else
		return "";
}

