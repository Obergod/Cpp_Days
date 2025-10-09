/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:54:09 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/07 17:54:11 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &name )
{
	_errMsg = name + "'s grade too high";
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &name )
{
	_errMsg = name + "'s grade too high";
}

Bureaucrat::Bureaucrat( const std::string &name, int grade ) : _name(name)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException(name);
	else if (grade < 1)
		throw GradeTooHighException(name);
	_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}	

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other )
{
	std::cout << "Bureaucrat assignement operator called" << std::endl;
	if (this != &other)
	{
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

std::string	Bureaucrat::getName()
{
	return _name;
}

int			Bureaucrat::getGrade()
{
	return _grade;
}

void		Bureaucrat::incGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException(_name);
	_grade--;
}

void		Bureaucrat::decGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException(_name);
	_grade++;
}


const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return _errMsg.c_str();
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return _errMsg.c_str();
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &br)
{
	os << br.getName() << ", bureaucrat grade " << br.getGrade() << "." << std::endl;
	
	return os;
}
