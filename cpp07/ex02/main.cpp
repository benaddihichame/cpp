#include "Array.hpp"

int main()
{
	Array<int> tabInt(2);
	tabInt[0] = 2;
	tabInt[1] = 1;
	std::cout << "tabInt " << tabInt[0] << "," << tabInt[1] << std::endl;

	Array<int> copyInt(tabInt);
	copyInt[0] = 999;
	std::cout << "Original: " << tabInt[0] << ", Copie: " << copyInt[0] << std::endl;

	Array<std::string> tabString(3);
	tabString[0] = "chien";
	tabString[1] = "chat";
	tabString[2] = "fish";

	for (unsigned int i = 0 ; i < tabString.size(); i++)
		std::cout << tabString[i] << " ";
	std::cout << std::endl;


	try 
	{
		tabInt[5] = 42;
	}
	catch(std::exception &e) {
		std::cout << "Exception !" << std::endl;
	}
	return 0;
}