#include "easyfind.hpp"

#include <iostream>
#include <algorithm>

int main()
{
	std::list<int> arr;
	int cible = 9;

	arr.push_back(0);
	arr.push_back(1);
	arr.push_back(9);

	if (easyfind<int>(arr, cible) == -1)
		std::cout << "Bad" << std::endl;
	else
		std::cout << "good" << std::endl;
}