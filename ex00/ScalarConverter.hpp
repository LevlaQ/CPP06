/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:09 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/04 19:51:18 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib> //strtod()
# include <limits> //for INT_MAX
# include <cctype> //isprint()
# include <iomanip> //setprecision()

enum e_pseudoLiteral
{
	P_INF,
	N_INF,
	NAN,
	REAL
};

struct s_Scalar
{
	double			value;
	const char		*c_string;
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
