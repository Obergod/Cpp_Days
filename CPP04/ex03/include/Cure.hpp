/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:29:03 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/03 19:29:04 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

# include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
		Cure();
		Cure( const Cure &other );
		Cure &operator=( const Cure &other );
		~Cure();
		virtual AMateria* clone() const;
		virtual void use(ICharacter &target);

};








#endif
