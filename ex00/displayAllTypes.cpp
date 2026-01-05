#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

static void displayInChar(const Type& type, const double& value)
{
	std::stringstream	output;

	output << "char: ";
	if (type == SPECIAL_TYPE)
		output << "impossible";
	else if (value < 0 || value > 127)
		output << "impossible";
	else if ((value >= 0 && value < 32)
			||(value > 126 && value <= 127))
		output << "Non displayable";
	else
		output << static_cast<char>(value);
	std::cout << output.str() << std::endl;
}

static void displayInInt(const Type& type, const double& value)
{
	std::stringstream	output;

	output<<"int: ";
	if (type == SPECIAL_TYPE)
		output << "impossible";
	else if (value < std::numeric_limits<int>::min()
			|| value > std::numeric_limits<int>::max())
		output << "impossible";
	else
		output << static_cast<int>(value);
	std::cout << output.str() << std::endl;
}

static void displayInFloat(const Type& type, const double& value, int& precision)
{
	std::stringstream	output;

	output<<"float: ";
	if (type == SPECIAL_TYPE)
		output << value << "f";
	else if (value < -std::numeric_limits<float>::max()
		|| value > std::numeric_limits<float>::max())
		output << "impossible";
	else
	{
		float fVal = static_cast<float>(value);
		if (fVal == std::floor(fVal))
			output << fVal << ".0";
		else
			output << std::setprecision(precision) << fVal;
		output << "f";
	}
	std::cout << output.str() << std::endl;
}


void displayInDouble(const Type& type, const double& value, int& precision)
{
	std::stringstream output;

	output <<"double: ";
	if (type != SPECIAL_TYPE && value == std::floor(value))
		output << value << ".0";
	else
		output<< std::setprecision(precision)<< value;
	std::cout << output.str() << std::endl;
}

void displayImpossible()
{
	std::cout << "char: impossible\n"
		<< "int: impossible\n"
		<< "float: impossible\n"
		<< "double: impossible\n";
}

/**
 * @brief display converted literal in other types
 *
 * @param type the literal's OWN TYPE
 * @param value the value in double VALIDED in literal's OWN TYPE	
 */
void	displayInAllTypes(const Type& type, const double& value, int& precision)
{
	std::cout << "precision is "<< precision <<"\n";
	displayInChar(type, value);
	displayInInt(type, value);
	displayInFloat(type, value, precision);
	displayInDouble(type, value, precision);
}
