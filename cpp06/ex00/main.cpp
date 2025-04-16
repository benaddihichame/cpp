#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		std::cout << "Examples:" << std::endl;
		std::cout << "  ./convert 0" << std::endl;
		std::cout << "  ./convert 42" << std::endl;
		std::cout << "  ./convert 4.2" << std::endl;
		std::cout << "  ./convert 4.2f" << std::endl;
		std::cout << "  ./convert nan" << std::endl;
		std::cout << "  ./convert +inf" << std::endl;
		std::cout << "  ./convert -inff" << std::endl;
		std::cout << "  ./convert a" << std::endl;
		return (1);
	}

	std::cout << "\nConverting: " << argv[1] << std::endl;
	std::cout << "----------------------------" << std::endl;

	ScalarConverter::convert(argv[1]);

	return (0);
}