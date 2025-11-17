/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:14:36 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/17 16:58:22 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pmerge::Pmerge() : _vecTime(0), _deqTime(0), _hasStraggler(0), _pairCount(0)
{
	std::cout << "Pmerge Default constructor called" << std::endl;
}

Pmerge::Pmerge( const Pmerge &other ) : _vecTime(other._vecTime), _deqTime(other._deqTime), _hasStraggler(other._hasStraggler),
										 _pairCount(other._pairCount), _vec(other._vec), _deq(other._deq)
{
	std::cout << "Pmerge copy constructor called" << std::endl;
}

Pmerge	&Pmerge::operator=( const Pmerge &other )
{
	if (this != &other)
	{
		_vecTime = other._vecTime;
		_deqTime = other._deqTime;
		_hasStraggler = other._hasStraggler;
		_pairCount = other._pairCount;
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
		if (!ss.eof())
			throw BadInputException();
	}
	_hasStraggler = (_vec.size() % 2 != 0) ? true : false;
	_pairCount = (_hasStraggler) ? _deq.size() - 1 : _deq.size();

	std::cout << "Before: ";
	for (int i = 0; i < _vec.size(); i++)
	{
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}

void	Pmerge::pairVec()
{
	for (int i = 0; i  < _pairCount; i += 2)
	{
		if (_vec[i] < _vec[i + 1])
			std::swap(_vec[i], _vec[i + 1]);
	}
}

void	Pmerge::pairDeq()
{
	for (int i = 0; i  < _pairCount; i += 2)
	{
		if (_deq[i] < _deq[i + 1])
			std::swap(_deq[i], _deq[i + 1]);
	}
}

void	Pmerge::sortPairsVec()
{
	for (int i = 0; i + 3  < _pairCount; i += 2)
	{
		for (int j = i + 2; j + 1  < _pairCount; j += 2)
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
	for (int i = 0; i + 3  < _pairCount; i += 2)
	{
		for (int j = i + 2; j + 1  < _pairCount; j += 2)
		{
			if (_deq[i] > _deq[j])
			{
				std::swap(_deq[i], _deq[j]);
				std::swap(_deq[i + 1], _deq[j + 1]);
			}
		}
		
	}
}

void	Pmerge::sortVec()
{
	pairVec();
	sortPairsVec();

	std::vector<int>	b;

	for (int i = 1; i  < _pairCount; i += 2)
		b.push_back(_vec[i]);
	if (_hasStraggler)
		b.push_back(_vec[_vec.size() - 1]);

	for (int i = _pairCount - 1; i >= 1; i -= 2)
		_vec.erase(_vec.begin() + i);

	if (_hasStraggler)
		_vec.erase(_vec.end() - 1);

	for (int i = 0; i < b.size(); i++)
	{
		std::vector<int>::iterator pos = 
			std::lower_bound(_vec.begin(), _vec.end(), b[i]);

		_vec.insert(pos, b[i]);
	}
}

void	Pmerge::sortDeq()
{
	pairDeq();
	sortPairsDeq();

	std::deque<int>	b;

	for (int i = 1; i  < _pairCount; i += 2)
		b.push_back(_deq[i]);
	if (_hasStraggler)
		b.push_back(_deq[_deq.size() - 1]);

	for (int i = _pairCount - 1; i >= 1; i -= 2)
		_deq.erase(_deq.begin() + i);

	if (_hasStraggler)
		_deq.erase(_deq.end() - 1);

	for (int i = 0; i < b.size(); i++)
	{
		std::deque<int>::iterator pos = 
			std::lower_bound(_deq.begin(), _deq.end(), b[i]);

		_deq.insert(pos, b[i]);
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

