/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 11:36:50 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/06 15:59:35 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
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