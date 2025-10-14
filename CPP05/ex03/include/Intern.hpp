/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 18:15:07 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/14 18:15:08 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <string>
#include <iostream>

class	Intern
{
	public:
		Intern();
		Intern( const Intern &other );
		Intern &operator=( const Intern&other );
		~Intern();

		AForm	*makeForm( const std::string &formName, const std::string &target);


};














#endif
