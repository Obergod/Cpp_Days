/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:36:55 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/13 17:37:05 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( const std::string &name, const int sGrade, const int eGrade) : _name(name),
														_signed(false), _sGrade(sGrade), _eGrade(eGrade)
{
	std::cout << "AForm default constructor called" << std::endl;
	if (sGrade > 150 || eGrade > 150)
		throw GradeTooLowException();
	else if (sGrade < 1 || eGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm( const AForm &other ) : _name(other._name), _signed(other._signed),
								_sGrade(other._sGrade), _eGrade(other._eGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
}	

AForm &AForm::operator=( const AForm &other )
{
	std::cout << "AForm assignement operator called" << std::endl;
	if (this != &other)
	{
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm default destructor called" << std::endl;
}

std::string	AForm::getName() const
{
	return _name;
}

int			AForm::getSGrade() const
{
	return _sGrade;
}

int			AForm::getEGrade() const
{
	return _eGrade;
}

int			AForm::getSigned() const
{
	return _signed;
}

void		AForm::beSigned( Bureaucrat &br )
{
	if (br.getGrade() > _sGrade)
		throw GradeTooHighException();
	_signed = true;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

std::ostream	&operator<<(std::ostream &os, const AForm &f)
{
	os << f.getName() << " form. grade needed to sign: " << f.getSGrade() <<
		" grade needed to exec: " << f.getEGrade() << 
		(f.getSigned() ? ". -signed-" : ". -not signed-") << std::endl;

	return os;
}
