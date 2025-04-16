#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return *this;
}
ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	(void)cpy;
}
bool isChar(std::string const value)
{
	if (value.size() == 1 && std::isdigit(value[0]) == false && std::isprint(value[0]) != 0)
		return true;
	return false;
}
bool isInt(std::string const value)
{
    if (value.empty())
        return false;
        
    size_t start = 0;
    if (value[0] == '-' || value[0] == '+')
        start = 1;
        
    for (size_t i = start; i < value.length(); i++)
    {
        if (!std::isdigit(value[i]))
            return false;
    }
    
    return value.length() > start;
}
bool isFloat(std::string const value)
{
	if (value[value.length() - 1] == 'f')
	{
		long unsigned int i = 0;
		while (i < value.length() - 1 && (std::isdigit(value[i]) || value[i] == '.'))
			i++;
		if (i == value.length() - 1)
			return true;
	}
	return false;
}
bool isSpecial(std::string const value)
{
	if (value == "-inf" || value == "+inf"|| value == "-inff" || value == "+inff" || value == "nan" || value == "nanf")
		return true;
	return false;
}
bool isDouble(std::string const value)
{
	if (value.find('.') != std::string::npos)
	{
		long unsigned int i = 0;
		while (std::isdigit(value[i]) || value[i] == '.')
			i++;
		if (i == value.length())
			return true;
	}
	return false;
}
bool isMinusInf(std::string const value)
{
	if (value == "-inf" || value == "-inff")
		return true;
	return false;
}
bool isPlusInf(std::string const value)
{
	if (value == "+inf" || value == "+inff")
		return true;
	return false;
}



void convertPlusinf(std::string const value)
{
	(void)value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << __FLT_MAX__ << "f" << std::endl;
	std::cout << "double: " << __DBL_MAX__ << std::endl;
}
void convertMinusinf(std::string const value)
{
	(void)value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << __FLT_MIN__ << "f" << std::endl;
	std::cout << "double: " << __DBL_MIN__ << std::endl;
}
void convertNan(std::string const value)
{
	(void)value;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
void convertInt(std::string const value)
{
	int number = atoi(value.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(number) << std::endl;

	std::cout << "int: " << number << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(number) << std::endl; 
}	
void convertFloat(std::string const value)
{
	float number = atof(value.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(number) << std::endl;

	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << number << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2) << static_cast<double>(number) << std::endl;
}
void convertChar(std::string const value)
{
	std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
	std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value[0]) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value[0]) << std::endl;

}
void convertDouble(std::string const value)
{
	double	number = atof(value.c_str());

	if (number < 0 || number > 127)
		std::cout << "char: impossible" << std::endl;
	else if (number < 32 || number == 127)
		std::cout << "char: non-displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(number) << std::endl;
	std::cout << "int: " << static_cast<int>(number) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) 
		<< static_cast<float>(number) << "f" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2) << number << std::endl;
}

void	error(void)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0 << std::endl;
	std::cout << "double: " << 0 << std::endl;
}

void ScalarConverter::convert(std::string const &input)
{
	if (isFloat(input) == true)
		convertFloat(input);
	else if (isChar(input) == true)
		convertChar(input);
	else if (isSpecial(input) == true)
	{
		if (isMinusInf(input) == true)
			convertMinusinf(input);
		else if (isPlusInf(input) == true)
			convertPlusinf(input);
		else 
			convertNan(input);
	}
	else if(isInt(input) == true)
		convertInt(input);
	else if (isDouble(input) == true)
		convertDouble(input);
	else
		error();
}