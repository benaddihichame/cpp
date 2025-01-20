#include "sed.hpp"

int main (int ac, char **av)
{
	if (ac == 4)
	{
		sed(av);
	}
	else
	{
		std::cout << "Please enter 4 args : a.out , filename, s1, s2\n";
	}
}