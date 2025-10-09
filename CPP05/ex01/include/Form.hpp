/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:56:10 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/09 20:56:11 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>

class	Form
{
	private:
		const std::string _name;
		bool	_signed;
		const int	_sGrade;
		const int	_eGrade;
	public:
		Form( const std::string &name, bool signed, const int sGrade, const int eGrade);
		Form( const Form &other );
		Form &operator=( const Form &other );
		~Form();
		std::string	getName();
		int			getGrade();

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
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat &br);









#endif
