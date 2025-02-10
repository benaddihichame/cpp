#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "Default Constructor WrongCat\n";
}
WrongCat::WrongCat(std::string type) : WrongAnimal(type)
{
	std::cout << "Args Constructor WrongCat\n";
}
WrongCat::WrongCat(const WrongCat& other)
{
	*this = other;
	std::cout << "Construcror copy WrongCat\n";
}
WrongCat& WrongCat::operator=(const WrongCat& cpy)
{
	std::cout << "Assignation operator WrongCat\n";
	if(&cpy != this)
	{
		this->type = cpy.type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat class: Destructor" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat class: Wrong miaou" << std::endl;
}