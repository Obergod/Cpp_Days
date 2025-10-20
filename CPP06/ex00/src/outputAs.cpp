/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outputAs.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:51:49 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/20 22:34:21 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

void	Scalar::outputAsChar(std::string &s)
{
	std::cout << "char: " << s[0] << std::endl;
	std::cout << "int: " << static_cast<int>(s[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(s[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<float>(s[0]) << ".0" << std::endl;
}

void	Scalar::outputAsInt(std::string &s)
{
	std::stringstream ss(s);
	int	i;
	ss >> i;
	
	if (i >= 32 && i <= 126)
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	else
		std::cout << "Error: Not convertible to char" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	Scalar::outputAsFloat(std::string &s)
{
	std::stringstream ss(s);
	float f;
	ss >> f;
	
	if (f >= 32 && f <= 126)
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "Error: Not convertible to char" << std::endl;
	std::cout << "int: " << static_cast<double>(f) << std::endl;
	std::cout << "float: " << s << std::endl;
	std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}
void	Scalar::outputAsDouble(std::string &s)
{
	std::stringstream ss(s);
	double	d;
	ss >> d;
	
	if (d >= 32 && d <= 126)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "Error: Not convertible to char" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << s << std::endl;
}

void	Scalar::outputAsNan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
