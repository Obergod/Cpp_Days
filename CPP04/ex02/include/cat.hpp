/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:27:27 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/30 19:27:29 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "animal.hpp"
# include "brain.hpp"
# include <iostream>
# include <string>

class	Cat : public Animal
{
	private:
		mutable Brain*	_brain;
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		virtual void	makeSound() const;
		virtual void	setIdea(int i, const std::string &idea) const;
		virtual std::string	getIdea(int i) const;
};






#endif
