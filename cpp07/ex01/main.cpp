#include "iter.hpp"

void printInt(int &n)
{
	std::cout << n << " ";
}

void	doubleValue(int &n)
{
	n *= 2;
}

void	printString(std::string &n)
{
	std::cout << n << " ";
}
int main()
{
	int array[5] = {1, 2, 3, 4, 5};
	std::cout << "Tableau de int: ";
	iter(array, 5, printInt);
	std::cout << std::endl;

	iter(array, 5 , doubleValue);
	std::cout << "Tableau valeur x2: ";
	iter(array, 5, printInt);
	std::cout << std::endl;

	std::string strArray[4] = {"chat", "chien", "fish", "bird"};
	std::cout << "Tableau de string: ";
	iter(strArray, 4, printString);
	std::cout << std::endl;

	return 0;
}