#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Im the Default constructor of Dog\n";
}

Dog::Dog(std::string type) : Animal(type)
{
	this->type = type;
	std::cout << "ARGS Constructor for " <<  type << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{	
	std::cout << "Constructor COPY Dog\n";
	*this = other;
}

Dog& Dog::operator=(const Dog& cpy)
{
	if (&cpy != this)
	{
		this->type = cpy.type;
	}
	std::cout << "Operator assignation Dog\n";
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Im a dog Waf Waf\n";
}

Dog::~Dog()
{
	std::cout << "Destructor Dog\n";
}