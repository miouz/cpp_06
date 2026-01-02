#include "ScalarConverter.hpp"
#include <limits>

//check error in literal's own type
void convertToType(const Type &type, const double &value) throw(std::invalid_argument)
{
	switch (type) {
		case INT_TYPE:
			if (value < std::INT_MIN || value > std::INT_MAX)
				throw std::invalid_argument("Overflow or underflow occurred");
			break;
		case FLOAT_TYPE:
			if (value < std::FLOAT_MIN| value > std::FLOAT_MAX)
				throw std::invalid_argument("Overflow or underflow occurred");
			break;	
		default:
			break;
	}
}

void ScalarConverter::convert(const std::string& literal)
{
	double	value;
	Type	literalType;

	try{
	literalType = getType(literal);
	value = getValue(literal, literalType);
	convertToType(literalType, value);
	displayInAllTypes(literalType, value);
	}catch(...)
	{
		displayImpossible();
	}
}
