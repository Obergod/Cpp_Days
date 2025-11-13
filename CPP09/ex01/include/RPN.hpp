/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:21:22 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/13 20:23:46 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <utility>
#include <stack>

class	Rpn
{
	private:
		std::stack<int>	_stack;
	public:
		Rpn();
		Rpn(const Rpn &other);
		Rpn &operator=(const Rpn &other);
		~Rpn();

		void	mainLoop( std::stringstream &ss );
		bool	isOperator( const std::string &token );
		int		applyOperator(int x, int y, char op);
		bool	isNb( const std::string &token );
		void	addNb( const std::string &token );

//		class	DateTooEarlyException : public std::exception
//		{
//			public:
//				virtual const char	*what() const throw();
//		};
};














#endif
