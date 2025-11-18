/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:56:03 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/18 16:32:50 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( const std::string &name, const int sGrade, const int eGrade) : _name(name),
														_signed(false), _sGrade(sGrade), _eGrade(eGrade)
{
	std::cout << "Form default constructor called" << std::endl;
	if (sGrade > 150 || eGrade > 150)
		throw FormGradeTooLowException();
	else if (sGrade < 1 || eGrade < 1)
		throw FormGradeTooHighException();
}

Form::Form( const Form &other ) : _name(other._name), _signed(other._signed),
								_sGrade(other._sGrade), _eGrade(other._eGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
}	

Form &Form::operator=( const Form &other )
{
	std::cout << "Form assignement operator called" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form default destructor called" << std::endl;
}

std::string	Form::getName()
{
	return _name;
}

int			Form::getSGrade()
{
	return _sGrade;
}

int			Form::getEGrade()
{
	return _eGrade;
}

int			Form::getSigned()
{
	return _signed;
}

void		Form::beSigned( Bureaucrat &br )
{
	if (br.getGrade() > _sGrade)
		throw BureaucratGradeTooLowException();
	_signed = true;
}

const char	*Form::FormGradeTooHighException::what() const throw()
{
	return "Form's grade too high";
}

const char	*Form::FormGradeTooLowException::what() const throw()
{
	return "Form's grade too low";
}

const char	*Form::BureaucratGradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade too low";
}

std::ostream	&operator<<(std::ostream &os, Form &f)
{
	os << f.getName() << " form. grade needed to sign: " << f.getSGrade() <<
		" grade needed to exec: " << f.getEGrade() << 
		(f.getSigned() ? ". -signed-" : ". -not signed-") << std::endl;

	return os;
}
