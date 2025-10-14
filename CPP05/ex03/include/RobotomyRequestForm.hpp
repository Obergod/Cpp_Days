/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:52:56 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/13 17:52:57 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class	RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm( const std::string &target );
		RobotomyRequestForm( const RobotomyRequestForm&other );
		RobotomyRequestForm &operator=( const RobotomyRequestForm&other );
		~RobotomyRequestForm();
		virtual void		execute(Bureaucrat const & executor) const;
};













#endif
