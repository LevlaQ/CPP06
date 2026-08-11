/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:09 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/11 17:08:57 by gyildiz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <cstdlib> //strtod()
# include <limits.h> //for INT_MAX
# include <cctype> //isprint()
# include <iomanip> //setprecision()

enum e_literal_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

enum e_pseudoLiteral
{
	P_INF,
	N_INF,
	N_NAN,
	REAL
};

struct s_Scalar
{
	char			c_value;
	int				i_value;
	double			d_value;
	float			f_value;
	const char		*c_string;
	int				str_length;
	e_pseudoLiteral	p_type;
	e_literal_type	l_type;
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		ScalarConverter	&operator=(const ScalarConverter &assign);
		
		~ScalarConverter();
	public:
		
		static void converter(std::string &literal);
		class ImproperLiteral : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

#endif
