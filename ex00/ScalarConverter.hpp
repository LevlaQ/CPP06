/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:09 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/03 18:03:16 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib> //strtod()
# include <limits> //for INT_MAX
# include <cctype> //isprint()

enum e_pseudoLiteral
{
	P_INF,
	N_INF,
	NAN,
	P_INFF,
	N_INFF,
	NANF,
	REAL
};

struct s_Scalar
{
	double			value;
	e_pseudoLiteral	type;
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		ScalarConverter	&operator=(const ScalarConverter &assign);
		
		~ScalarConverter();
	public:
		
		static void converter(std::string &literal); //kopyalasa ne olur referans alsa ne olur
		class ImproperLiteral : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

#endif
