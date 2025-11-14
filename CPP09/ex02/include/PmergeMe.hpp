/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 21:03:25 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/14 19:11:16 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <vector>
#include <deque>
#include <ctime>


class	Pmerge
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		int	_vecTime;
		int	_deqTime;
	public:
		Pmerge();
		Pmerge(const Pmerge &other);
		Pmerge &operator=(const Pmerge &other);
		~Pmerge();

		void	parseInput(int ac, char **av);

		void	pairVec();
		void	pairDeq();
		void	sortPairsVec();
		void	sortPairsDeq();
		void	sortVec();
		void	sortDeq();
		void	sort();

		class	NegativeNbException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class	BadInputException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};














#endif

