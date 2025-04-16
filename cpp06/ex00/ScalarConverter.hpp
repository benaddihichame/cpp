#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cmath>
#include <climits>
#include <cctype>
#include <cfloat>
#include <cstdlib>
#include <cerrno>
#include <iomanip>


class ScalarConverter
{
	private:
	ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &cpy);
	ScalarConverter(const ScalarConverter &cpy);
	~ScalarConverter();
	public:
	static void convert(std::string const &litral);
};
	bool isChar(std::string const value);
	bool isInt(std::string const value);
	bool isFloat(std::string const value);
	bool isSpecial(std::string const value);
	bool isDouble(std::string const value);
	bool isMinusInf(std::string const value);
	bool isPlusInf(std::string const value);
	void convertPlusinf(std::string const value);
	void convertMinusinf(std::string const value);
	void convertNan(std::string const value);
	void convertInt(std::string const value);
	void convertFloat(std::string const value);
	void convertChar(std::string const value);
	void convertDouble(std::string const value);

	void error(void);
#endif