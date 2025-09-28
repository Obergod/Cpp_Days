/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:56:03 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/28 15:56:04 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed original_area = Point::calcTriangleArea(a, b, c);


	Fixed area1 = Point::calcTriangleArea(point, a, b);
	Fixed area2 = Point::calcTriangleArea(point, b, c);
	Fixed area3 = Point::calcTriangleArea(point, c, a);
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;

	Fixed	sum_area = area1 + area2 + area3;
	return (original_area == sum_area);
}
