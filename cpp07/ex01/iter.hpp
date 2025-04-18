#ifndef ITER_HPP
# define ITER_HPP
#include <string>
#include <iostream>

template<typename T>
void iter(T *string, int lenght, void func(T &))
{
	for (int i =0; i < lenght; i++)
		func(string[i]);
}
#endif