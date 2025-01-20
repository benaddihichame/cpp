#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void	Harl::debug()
{
	std::cout << "THIS IS DEBUG" << std::endl;
}
void	Harl::info()
{
	std::cout << "THIS IS INFO" << std::endl;
}
void	Harl::warning()
{
	std::cout << "THIS IS WARNING" << std::endl;
}
void	Harl::error()
{
	std::cout << "THIS IS ERROR" << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;

	void (Harl::*tab[])() = {&Harl::debug, &Harl::error, &Harl::warning, &Harl::info};

	std::string	levels[]= {
		"debug",
		"error",
		"warning",
		"info",
	};

	while (i < 4)
	{
		if(levels[i] == level)
		{
			(this->*tab[i])();
			return ;
		}
		i++;
	}
}

