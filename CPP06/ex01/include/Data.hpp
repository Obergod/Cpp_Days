/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:58:47 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 19:33:18 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <string>
#include <iostream>


class Data	
{
	private:
		std::string _name;
		std::string _desc;
		int			_nbHead;
		int			_nbEyes;
	public:
		Data();
		Data( const std::string desc, const std::string &name, int nbHead, int nbEyes );
		Data( const Data &other );
		Data &operator=( const Data &other );
		~Data();

		std::string getName();
		std::string getDesc();
		int getNbHead();
		int getNbEyes();
};








#endif

