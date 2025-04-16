#include "Base.hpp"
#include <iostream>

int	main()
{
	srand(time(NULL));
	Base *x(generate());
	Base *y(generate());
	Base *z(generate());

	identify(x);
	identify(y);
	identify(z);

	std::cout << std::endl;
	
	identify(*x);
	identify(*y);
	identify(*z);
	delete x;
	delete y;
	delete z;
}