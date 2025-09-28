/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 15:55:54 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/29 15:55:55 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x( 0 ), _y( 0 )
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Point Default Constructor Called" << std::endl;
#endif
}

Point::Point( const float f1, const float f2 ): _x( f1 ), _y( f2 )
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Point Float Constructor Called" << std::endl;
#endif
}

Point::Point( const Point &other ): _x(other._x), _y(other._y)
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Point copy Constructor Called" << std::endl;
#endif
}

Point	&Point::operator=( const Point &other)
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Point Copy Assignment Operator Called" << std::endl;
#endif
	return (*this);
}

Point::~Point()
{
#ifndef NO_DEBUG_CONSTRUCTORS
	std::cout << "Point Default Destructor Called" << std::endl;
#endif
}

Fixed	Point::calcTriangleArea(const Point &p1, const Point &p2, const Point &p3)
{
	Fixed	x1 = p1._x;
	Fixed	y1 = p1._y;
	Fixed	x2 = p2._x;
	Fixed	y2 = p2._y;
	Fixed	x3 = p3._x;
	Fixed	y3 = p3._y;

	Fixed result = x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2);
	if (result < Fixed(0))
		result = result * Fixed(-1);

	Fixed area = Fixed(0.5f) * result;
	return (area);
}
