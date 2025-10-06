/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 19:45:44 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/03 19:45:45 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCTER_HPP
# define CHARCTER_HPP

#include <iostream>
#include <string>

class	AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter() {}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class	Character : public ICharacter
{
	private:
		AMateria	*_inventory[4];
		std::string	_name;
		int			_materiaNb;
	public:
		Character( std::string name );
		Character( const Character &other );
		Character &operator=( const Character &other );
		~Character();
		virtual std::string const &getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

	
};




#endif
