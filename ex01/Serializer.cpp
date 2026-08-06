/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 12:11:40 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/06 15:27:34 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructer called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	(void)copy;
	std::cout << "Serializer copy constructer called" << std::endl;
}

Serializer	&Serializer::operator=(const Serializer &assign)
{
	(void)assign;
	std::cout << "Serializer copy assignment operator called" << std::endl;
	return(*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructer called" << std::endl;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t adress;
	
	adress = reinterpret_cast<uintptr_t>(ptr);
	return (adress);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	Data	*ptr;

	ptr = reinterpret_cast<Data *>(raw);
	return(ptr);
}