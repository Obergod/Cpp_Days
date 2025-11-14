/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:14:36 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/14 21:14:01 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pmerge::Pmerge() : _vecTime(0), _deqTime(0)
{
	std::cout << "Pmerge Default constructor called" << std::endl;
}

Pmerge::Pmerge( const Pmerge &other ) : _vecTime(other._vecTime), _deqTime(other._deqTime),
										_vec(other._vec), _deq(other._deq)
{
	std::cout << "Pmerge copy constructor called" << std::endl;
}

Pmerge	&Pmerge::operator=( const Pmerge &other )
{
	if (this != &other)
	{
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
		_vec = other._vec;
		_deq = other._deq;
	}
	std::cout << "Pmerge assignement operator called" << std::endl;
	return (*this);
}

Pmerge::~Pmerge()
{
	std::cout << "Pmerge Default destructor called" << std::endl;
}

const char	*Pmerge::NegativeNbException::what() const throw()
{
	return ("Error: Negative number detected");
}

const char	*Pmerge::BadInputException::what() const throw()
{
	return ("Error: Bad input");
}

void	Pmerge::parseInput(int ac, char **av)
{
	for (int i = 0; i < ac; i++)
	{
		std::stringstream	ss(av[i]);
		int	nb;

		while (ss >> nb)
		{
			if (nb < 0)
				throw NegativeNbException();

			_vec.push_back(nb);
			_deq.push_back(nb);
		}
//		if (!ss.eof())
//			throw BadInputException();
	}

	std::cout << "Before: ";
	for (int i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

void	Pmerge::pairVec()
{
	for (std::vector<int>::iterator it = _vec.begin();
			it + 1 != _vec.end(); it += 2)
	{
		if (*it < *(it + 1))
			std::swap(*it, *(it + 1));
	}
}

void	Pmerge::pairDeq()
{
	for (std::deque<int>::iterator it = _deq.begin();
			it + 1 != _deq.end(); it += 2)
	{
		if (*it < *(it + 1))
			std::swap(*it, *(it + 1));
	}
}

void	Pmerge::sortPairsVec()
{
	for	(int i = 0; i + 3 < _vec.size(); i += 2)
	{
		for (int j = i + 2; j + 1 != _vec.size(); j += 2)
		{
			if (_vec[i] > _vec[j])
			{
				std::swap(_vec[i], _vec[j]);
				std::swap(_vec[i + 1], _vec[j + 1]);
			}
		}
		
	}
}

void	Pmerge::sortPairsDeq()
{
	for	(int i = 0; i + 3 < _deq.size(); i += 2)
	{
		for (int j = i + 2; j + 1 != _deq.size(); j += 2)
		{
			if (_deq[i] > _deq[j])
			{
				std::swap(_deq[i], _deq[j]);
				std::swap(_deq[i + 1], _deq[j + 1]);
			}
		}
		
	}
}

//	Fix For even or uneven string
void	Pmerge::sortVec()
{
	pairVec();
	sortPairsVec();

	std::vector<int>	b;

	for (int i = 1; i + 1 < _vec.size(); i += 2)
		b.push_back(_vec[i]);
	if (_vec.size() % 2 != 0)
		b.push_back(_vec[_vec.size() - 1]);

	for (int i = 1; i + 1 < _vec.size(); i++)
		_vec.erase(_vec.begin() + i);

	if (_vec.size() % 2 != 0)
		_vec.erase(_vec.end() - 1);

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < _vec.size(); j++)
		{
			if (b[i] < _vec[j])
			{
				_vec.insert(_vec.begin() + j, b[i]);
				break ;
			}
		}
	}
}

void	Pmerge::sortDeq()
{
	pairDeq();
	sortPairsDeq();

	std::deque<int>	b;

	// if dosent work add _deq[_deq.size - 1]
	for (int i = 1; i + 1 < _deq.size(); i++)
	{
		b.push_back(_deq[i]);
		_deq.erase(_deq.begin() + i);
	}

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < _deq.size(); j++)
		{
			if (b[i] < _deq[j])
			{
				_deq.insert(_deq.begin() + j, b[i]);
				break ;
			}
		}
	}
}

void	Pmerge::sort()
{
	clock_t vStart = clock();
    sortVec();
    clock_t vEnd = clock();
    
    double vecTime = static_cast<double>(vEnd - vStart) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "After: ";
	for (int i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;

	clock_t dStart = clock();
    sortDeq();
    clock_t dEnd = clock();
    
    double deqTime = static_cast<double>(dEnd - dStart) / CLOCKS_PER_SEC * 1000000;
	
	std::cout << "Time to process a range of " << _vec.size()
			<< " elements with std::vector : " << vecTime << std::endl;

	std::cout << "Time to process a range of " << _deq.size()
			<< " elements with std::deque : " << deqTime << std::endl;
}

