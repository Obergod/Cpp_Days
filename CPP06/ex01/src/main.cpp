/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafioron <mafioron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 19:19:51 by mafioron          #+#    #+#             */
/*   Updated: 2025/10/21 19:45:40 by mafioron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data *originalHuman = new Data();
	std::cout << std::endl;

	std::cout << "Human pointer address: " << originalHuman << std::endl;
	std::cout << "original name: " << originalHuman->getName()
			  << " | original desc: " << originalHuman->getDesc() << std::endl;
	std::cout << std::endl;
	
	uintptr_t raw = Serializer::serialize(originalHuman);
	std::cout << "Serialized raw value: " << raw << std::endl;
	std::cout << std::endl;

	Data* deserializedHuman = Serializer::deserialize(raw);
	std::cout << "deserialized Human: " << deserializedHuman << std::endl;
	std::cout << "deserialized name: " << deserializedHuman->getName()
			  << " | deserialized desc: " << deserializedHuman->getDesc() << std::endl;
	std::cout << std::endl;
	
	if (originalHuman == deserializedHuman)
		std::cout << "sucess! Both point at the same place" << std::endl;
	else
		std::cout << "Failure! They do not point at the same place :(" << std::endl;
	std::cout << std::endl;

	delete originalHuman;
}
