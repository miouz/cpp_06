#include "ScalarConverter.hpp"
#include <sstream>
#include <iostream>

void displayInChar(const Type& type, const double& value)
{
	char c;
	std::stringstream	output("char : ");

	if (value < 0 || value > 127)
		output << "Impossible";
	else if (c < 32 || c > 126)
		output << "Non displayable";
	else
		output << static_cast<char>(value);
	std::cout << output.str() << std::endl;
}

void displayInInt(const Type& type, const double& value)
{

}

void displayInFloat(const Type& type, const double& value)
{

}

void displayInDouble(const Type& type, const double& value)
{

}

void	displayInAllTypes(const Type& type, const double& value)
{
	displayInChar(type, value);
	displayInInt(type, value);
	displayInFloat(type, value);
	displayInDouble(type, value);
}
