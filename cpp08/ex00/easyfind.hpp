#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <string>
#include <iostream>
#include <algorithm>
#include <list>

template<typename T>
int	easyfind(std::list<T> array, int cible)
{
	std::list<int>::const_iterator i;

	i = std::find(array.begin(), array.end(), cible);
	if (i != array.end())
		return(0);
	return -1;
};
#endif