/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:27:04 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/30 19:27:06 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP


# include <iostream>
# include <string>

class	Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual void	makeSound() const = 0;
		std::string	getType() const;
		virtual void	setIdea(int i, const std::string &idea) const = 0;
		virtual std::string	getIdea(int i) const = 0;
};






#endif
