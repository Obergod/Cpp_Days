/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 20:24:40 by mafioron          #+#    #+#             */
/*   Updated: 2025/09/11 20:24:41 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "memory adress of str : " << &str << std::endl;
	std::cout << "memory adress of ptr : " << stringPTR << std::endl;
	std::cout << "memory adress of ref : " << &stringREF << std::endl;
	std::cout << "str from str : " << str << std::endl;
	std::cout << "str from ptr : " << *stringPTR << std::endl;
	std::cout << "str from ref : " << stringREF << std::endl;
}
