#include "Animal.hpp"

Animal::Animal() : type("")
{
	std::cout << "Im the Default constructor of Animal\n";
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "ARGS Animal Constructor for " <<  type << std::endl;
}

Animal::Animal(const Animal& other)
{	
	std::cout << "Constructor COPY ANIMAL\n";
	*this = other;
}

Animal& Animal::operator=(const Animal& cpy)
{
	if (&cpy != this)
	{
		this->type = cpy.type;
	}
	std::cout << "Operator assignation ANIMAL\n";
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "im a tiger grrr\n";
}

std::string Animal::getType() const
{
	return this->type;
}
Animal::~Animal()
{
	std::cout << "Destructor ANIMAL\n";
}