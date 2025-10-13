/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:53:16 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/13 17:53:17 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm( const std::string &target );
		PresidentialPardonForm( const PresidentialPardonForm &other );
		PresidentialPardonForm &operator=( const PresidentialPardonForm&other );
		~PresidentialPardonForm();
		virtual void		execute(Bureaucrat const & executor) const;

};











#endif
