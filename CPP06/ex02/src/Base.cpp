/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:37:42 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 21:40:52 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Letters.hpp"

Base::~Base()
{
	std::cout << "Base Default Constructor called" << std::endl;
}

Base	*generate()
{
	int	r = rand() % 3;

	switch (r)
	{
		case(0):
			return new A();
		case(1):
			return new B();
		case (2):
			return new C();
		default:
			return NULL;
	}
}

void	identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "not of any of those class" << std::endl;
}

void	identify( Base& p )
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...)
	{}
	
	std::cout << "not of any of those class" << std::endl;
}
