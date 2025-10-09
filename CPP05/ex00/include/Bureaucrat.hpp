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

class	Bureaucrat
{
	private:
		std::string _name;
		int	_grade;
	public:
		Bureaucrat( const std::string &name, int grade );
		Bureaucrat( const Bureaucrat &other );
		Bureaucrat &operator=( const Bureaucrat &other );
		~Bureaucrat();
		std::string	getName();
		int			getGrade();
		void		incGrade();
		void		decGrade();
		
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Bureaucrat &br);







#endif
