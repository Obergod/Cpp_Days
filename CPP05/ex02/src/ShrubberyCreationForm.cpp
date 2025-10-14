/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:52:23 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/13 17:52:24 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : AForm(other), _target(other._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}	

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other )
{
	std::cout << "ShrubberyCreationForm assignement operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

//Gotta do exec grade execption
void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getEGrade())
		throw GradeTooHighException();

	std::string	name = _target + "_shrubbery";
	std::ofstream	file(name.c_str());

	if (!file)
	{
		std::cerr << _target << " File failed to create" << std::endl;
		return ;
	}

	file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    file << "\n";

	std::cout << name << ", created" << std::endl;
}
