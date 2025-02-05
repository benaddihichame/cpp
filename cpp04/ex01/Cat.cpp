#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	std::cout << "Im the Default constructor of Cat\n" ;
}

Cat::Cat(std::string type) : Animal(type)
{
	this->type = type;
	std::cout << "ARGS Constructor for " <<  type  << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{	
	std::cout << "Constructor COPY Cat\n";
	*this = other;
}

Cat& Cat::operator=(const Cat& cpy)
{
	if (&cpy != this)
	{
		this->type = cpy.type;
	}
	std::cout << "Operator assignation Cat\n";
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Im a Cat Miaou Miaou\n" ;
}

Cat::~Cat()
{
	std::cout << "Destructor Cat\n";
}