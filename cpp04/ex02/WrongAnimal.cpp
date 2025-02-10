#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(): type("")
{
	std::cout << "WrongAnimal DEFAULT constructor\n";
}
WrongAnimal::WrongAnimal(std::string ko)
{
	this->type = ko;
	std::cout << "WrongAnimal ARGS constructor\n";
}
WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	*this = other;
	std::cout << "WrongAnimal cpy constructor \n";

}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal &cpy)
{
	if(&cpy != this)
	{
		this->type = cpy.type;
	}
	std::cout << "WrongAnimal assignation operator \n";
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor \n";
}
std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal Animal sound\n";
}