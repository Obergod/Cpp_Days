/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 16:52:30 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/22 17:09:52 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <cmath>

template <typename T> 
void swap(T &x, T &y)
{
	T temp = x;
	x = y;
	y = temp;
}

template <typename T>
T max(T x, T y) 
{
	return (x > y) ? x : y;
}

template <typename T>
T min(T x, T y) 
{
	return (x < y) ? x : y;
}




#endif
