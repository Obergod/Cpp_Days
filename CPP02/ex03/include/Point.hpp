/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:56:19 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/28 15:56:20 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP


# include "Fixed.hpp"

class	Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		Point(const float f1, const float f2);
		Point(const Point &other);
		Point	&operator=(const Point &other);
		~Point();
		static Fixed	calcTriangleArea(const Point &p1, const Point &p2, const Point &p3);
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);





#endif
