/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:14:58 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/14 18:14:59 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern( const Intern &other )
{
	(void)other;
	std::cout << "Intern copy constructor called" << std::endl;
}	

Intern &Intern::operator=( const Intern &other )
{
	std::cout << "Intern assignement operator called" << std::endl;
	if (this != &other)
	{
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called" << std::endl;
}

AForm	*Intern::makeForm( const std::string &formName, const std::string &target)
{
	std::string forms[3];
	forms[0] = "PresidentialPardonForm";
	forms[1] = "RobotomyRequestForm"; 
	forms[2] = "ShrubberyCreationForm";

	int	i = -1;
	while (++i < 3)
	{
		if (formName == forms[i])
			break ;
	}
	switch (i)
	{
		case (0):
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		case (1):
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case (2):
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		default:
			std::cerr << "Error: Form does not exist" << std::endl;
			return NULL;
	}
}

