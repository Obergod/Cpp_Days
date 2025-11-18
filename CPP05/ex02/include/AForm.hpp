/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:37:17 by mafioron          #+#    #+#             */
/*   Updated: 2025/11/18 16:43:37 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class	AForm
{
	private:
		const std::string _name;
		bool	_signed;
		const int	_sGrade;
		const int	_eGrade;
	public:
		AForm( const std::string &name, const int sGrade, const int eGrade);
		AForm( const AForm &other );
		AForm &operator=( const AForm &other );
		virtual ~AForm();
		std::string	getName() const;
		int			getSGrade() const;
		int			getEGrade() const;
		int			getSigned() const;
		void		beSigned( Bureaucrat &br );
		virtual void		execute(Bureaucrat const & executor) const = 0;


		class	FormGradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	FormGradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class	BureaucratGradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, const AForm &f);









#endif
