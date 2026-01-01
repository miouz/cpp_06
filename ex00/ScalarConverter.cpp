#include "ScalarConverter.hpp"
#include <iostream>
#include <exception>

enum literalType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

union value
{
	char	c;
	int		intVal;
	float	fVal;
	double	dVal;
};

typedef void (*convertFunc)(const std::string& literal);


void	outputValue(const std::string& charDisplay, const std::string& intDisplay,
				 const std::string& floatDisplay, const std::string& doubleDisplay)
{
	std::cout << "char: " << charDisplay << "\n"
		<< "int: " << intDisplay << "\n"
		<< "float: " << floatDisplay << "\n"
		<< "double: " << doubleDisplay << "\n";
}

void	outputNegativeInf(const std::string& literal)
{
	outputValue("impossbile", "impossbile", "-inff", "-inf");
}

void	outputPositiveInf(const std::string& literal)
{
	outputValue("impossbile", "impossbile", "+inff", "+inf");
}

void	outputNan(const std::string& literal)
{
	outputValue("impossbile", "impossbile", "nanf", "nan");
}

convertFunc	getConvertFunc(const std::string& literal)
{
	//for special scientific literals
	std::string	specialFloatLiterals[4] = {"-inff", "inff", "+inff","nanf"};
	std::string	specialDoubleLiterals[4] = {"-inf", "inf", "+inf","nan"};
	convertFunc	SpecialLiterals[4] = {&outputNegativeInf, &outputPositiveInf, &outputPositiveInf, &outputNan};

	//if is special literals
	for (int i = 0; i < 4; i++)
	{
		if (literal == specialFloatLiterals[i]
			|| literal == specialDoubleLiterals[i])
			return SpecialLiterals[i];
	}

	//if is numeric
	if (isNumeric(literal) == true)

}

void	ScalarConverter::convert(const std::string &literal)
{
	convertFunc convertFunction = getConvertFunc(literal);
	try {
		convertFunction(literal);
	} catch (std::exception& e) {
		std::cout<< "Error: " << e.what() <<"\n";
	}
}
