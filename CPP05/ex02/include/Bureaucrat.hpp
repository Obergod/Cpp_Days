/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 17:54:28 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/07 17:54:29 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

class	Bureaucrat
{
	private:
		const std::string _name;
		int	_grade;
	public:
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat &operator=( const Bureaucrat &other );
		~Bureaucrat();
		std::string	getName() const;
		int			getGrade() const;
		void		incGrade();
		void		decGrade();
		void		signForm(AForm &form);
		void		executeForm(AForm const &form);
		
		class	GradeTooHighException : public std::exception
		{
			private:
				std::string _errMsg;
			public:
				GradeTooHighException( const std::string &name );
				virtual ~GradeTooHighException() throw();
				virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			private:
				std::string _errMsg;
			public:
				GradeTooLowException( const std::string &name );
				virtual ~GradeTooLowException() throw();
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &br);







#endif
