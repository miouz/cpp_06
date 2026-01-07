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
	else if ((value >= 0 && value <= 127)
			&& !isprint(value))
		output << "Non displayable";
	else
		output << static_cast<char>(value);
	std::cout << output.str() << "\n";
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
	std::cout << output.str() << "\n";
}

static void displayInFloat(const Type& type, const double& value)
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
		output << fVal;
		if (output.str().find('.') == std::string::npos
			&& output.str().find('e') == std::string::npos)
			output << ".0";
		output << "f";
	}
	std::cout << output.str() << "\n";
}


void displayInDouble(const Type& type, const double& value)
{
	std::stringstream output;

	output <<"double: " << value;
	if (type != SPECIAL_TYPE
	 	&& output.str().find('.' ) == std::string::npos
		&& output.str().find('e', 6) == std::string::npos)
		output << ".0";
	std::cout << output.str() << "\n";
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
void	displayInAllTypes(const Type& type, const double& value)
{
	displayInChar(type, value);
	displayInInt(type, value);
	displayInFloat(type, value);
	displayInDouble(type, value);
}
