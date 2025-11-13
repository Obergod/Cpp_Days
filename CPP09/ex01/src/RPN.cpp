/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:40:35 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/13 20:41:28 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn()
{
	std::cout << "Rpn Default constructor called" << std::endl;
}

Rpn::Rpn( const Rpn &other ) : _stack(other._stack) 
{
	std::cout << "Rpn copy constructor called" << std::endl;
}

Rpn	&Rpn::operator=( const Rpn &other )
{
	if (this != &other)
	{
		_stack = other._stack;
	}
	std::cout << "Rpn assignement operator called" << std::endl;
	return (*this);
}

Rpn::~Rpn()
{
	std::cout << "Rpn Default destructor called" << std::endl;
}

void	Rpn::mainLoop( std::stringstream &ss )
{
	std::string	token;

	while (ss >> token)
	{
		if (isOperator(token))	
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Erorr: invalid input, Operator missplaced");

			int	a = _stack.top();
			_stack.pop();
			int	b = _stack.top();
			_stack.pop();
			
			_stack.push(applyOperator(b, a, token[0]));
		}
		else if (isNb(token))
		{
			addNb(token);			
		}
		else
		{
			throw std::runtime_error("Erorr: invalid input");
		}
	}		

	if (_stack.size() != 1)
		throw std::runtime_error("Erorr: invalid input, Not enough operator");

	std::cout << _stack.top() << std::endl;
}

bool	Rpn::isNb( const std::string &token )
{
	std::stringstream ss(token);
	int	nb;
	
	return (ss >> nb && ss.eof());
}

void	Rpn::addNb( const std::string &token )
{
	std::stringstream ss(token);
	int	nb;

	ss >> nb;
	_stack.push(nb);
}

int	Rpn::applyOperator(int x, int y, char op)
{
	switch (op)
	{
		case '-':
			return x - y;
		case '+':
			return x + y;
		case '*':
			return x * y;
		case '/':
			return x / y;
		default:
			return 0;
	}
}

bool	Rpn::isOperator( const std::string &token )
{
	return (token.length() == 1 && (token == "+" || token == "-"
				|| token == "/" || token == "*"));
}
