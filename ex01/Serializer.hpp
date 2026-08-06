/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:36:50 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/06 15:29:54 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H
# include <iostream>
# include <iomanip>

# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	private:
	Serializer();
	Serializer(const Serializer &copy);
	
	Serializer	&operator=(const Serializer &assign);

	~Serializer();
	public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};



#endif