#ifndef SCALARCONVERT_HPP_
#define SCALARCONVERT_HPP_

#include <exception>
#include <string>
#include <stdexcept>
#include <limits>
#include <iostream>
#include <cmath>
#include <cerrno>


enum Type
{
	CHAR_TYPE,
	INT_TYPE,
	FLOAT_TYPE,
	DOUBLE_TYPE,
	SPECIAL_TYPE,
};

class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	public:
	static void convert(const std::string& literal);
};

Type	getType(const std::string& literal);
double	getValue(const std::string& literal, const Type& type);
void	displayInAllTypes(const Type& type, const double& value);
void	displayImpossible();
#endif // !SCALARCONVERT_HPP_
