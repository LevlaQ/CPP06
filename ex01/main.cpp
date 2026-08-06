/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 15:03:54 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/06 15:33:38 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data		logbook;
	uintptr_t  	raw_adress;
	Data		*shelf;

	logbook.Bureaucrat_grade = 56;
	logbook.Bureaucrat_name = "Sheldon";
	shelf = &logbook;
	
	std::cout << "Adress held by shelf pointer before cast: " << shelf <<\
	 std::endl;
	
	raw_adress = Serializer::serialize(shelf);
	std::cout << "Value of raw_adress: " << raw_adress << std::endl;

	std::cout << "Let's see the uintptr_t version of the 'shelf' :";
	std::cout << std::fixed << std::setprecision(1) <<\
	 reinterpret_cast<uintptr_t>(shelf)<< std::endl;
	
	shelf = Serializer::deserialize(raw_adress);
	std::cout << "Adress held by shelf pointer after cast: " << shelf <<\
	 std::endl;

	std::cout << "\n";
	
	std::cout << shelf->Bureaucrat_grade << std::endl;
	std::cout << shelf->Bureaucrat_name << std::endl;
}

