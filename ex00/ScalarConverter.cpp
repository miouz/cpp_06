#include "ScalarConverter.hpp"
#include <limits>
#include <iostream>

//check error in literal's own type
void convertToType(const Type &type, const double& value) throw(std::invalid_argument)
{
	if (type == INT_TYPE)
		if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
			throw std::invalid_argument("Overflow or underflow occurred");
}

int getPrecision(const std::string& literal)
{
	int i = 0;
	int precision = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	while (std::isdigit(literal[i]))
	{
		i++;
		precision++;
	}
	if (literal[i] == '.')
		i++;
	while (std::isdigit(literal[i])) 
	{
		i++;
		precision++;
	}
	return precision;
}

void ScalarConverter::convert(const std::string& literal)
{
	double	value;
	Type	literalType = INT_TYPE;
	int		precision = 0;

	try{
	literalType = getType(literal);
	std::cout << " literalType: "<< literalType << "\n";
	if (literalType == FLOAT_TYPE || literalType == DOUBLE_TYPE)
		precision = getPrecision(literal);
	value= getValue(literal, literalType);
	convertToType(literalType, value);
	displayInAllTypes(literalType, value, precision);
	}catch(...)
	{
		displayImpossible();
	}
}
