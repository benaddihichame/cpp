#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
	std::cout << "Im the Default constructor of AAnimal\n";
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
	std::cout << "ARGS AAnimal Constructor for " <<  type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{	
	std::cout << "Constructor COPY AANIMAL\n";
	*this = other;
}

AAnimal& AAnimal::operator=(const AAnimal& cpy)
{
	if (&cpy != this)
	{
		this->type = cpy.type;
	}
	std::cout << "Operator assignation AANIMAL\n";
	return *this;
}

void AAnimal::makeSound(void) const
{
	std::cout << "im a tiger grrr\n";
}

std::string AAnimal::getType() const
{
	return this->type;
}
AAnimal::~AAnimal()
{
	std::cout << "Destructor AANIMAL\n";
}