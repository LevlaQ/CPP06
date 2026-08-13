/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyildiz <gyildiz@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 13:28:09 by gyildiz           #+#    #+#             */
/*   Updated: 2026/08/13 16:53:07 by gyildiz          ###   ########.fr       */
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
# include <cstring> //strchr()
# include <sstream> //string stream

# define WS "\t\r\n\v "
# define SIGN "+-.f"

enum e_literal_type
{
	P_INF,
	N_INF,
	N_NAN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

struct s_Scalar
{
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
		
		static void convert(std::string &literal);
		class StreamError : public std::exception
		{
			virtual const char	*what() const throw();
		};
		class ImproperLiteral : public std::exception
		{
			virtual const char	*what() const throw();
		};
};

#endif
