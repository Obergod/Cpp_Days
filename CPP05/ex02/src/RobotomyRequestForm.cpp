/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:52:48 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/13 17:52:49 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string &target ) : AForm("RobotomyRequestForm", 145, 137), _target(target)
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : AForm(other), _target(other._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}	

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other )
{
	std::cout << "RobotomyRequestForm assignement operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getSGrade())
		throw GradeTooHighException();
	std::cout << "--- Robotomy procedure starting ---" << std::endl;
	usleep(50000);
	std::cout << "* DRILLING NOISE *" << std::endl;
	sleep(1);

	if (rand() % 2 == 0)
		std::cout << _target << " Has been robotomized" << std::endl;
	else
		std::cout << _target << " Robotomy has failed" << std::endl;
}
