/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 19:53:58 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/31 20:01:10 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <vector>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack &other): std::stack<T>( other ) {};
		MutantStack &operator=( const MutantStack &other )
		{
			if (this != other)
				std::stack<T>::operator=( other );
			return (*this);
		}
		~MutantStack() {};
		
		typedef typename std::stack<T>::container_type::iterator iterator;
		
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};











#endif
