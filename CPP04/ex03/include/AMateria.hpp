/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:25:50 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/03 19:25:51 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria(std::string const &type);
		AMateria( const AMateria &other );
		AMateria &operator=( const AMateria &other );
		virtual ~AMateria();
		std::string const &getType() const; 
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter &target);
};







#endif
