#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
	this->brain = new Brain();
	std::cout << "Im the Default constructor of Dog\n";
}

Dog::Dog(std::string type) : AAnimal(type)
{
	this->type = type;
	this->brain = new Brain();
	std::cout << "ARGS Constructor for " <<  type << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other)
{	
	std::cout << "Constructor COPY Dog\n";
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& cpy)
{
	if (&cpy != this)
	{
		this->brain = new Brain(*cpy.brain);
		this->type = cpy.type;
	}
	std::cout << "Operator assignation Dog\n";
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Im a dog Waf Waf\n";
}

void Dog::addIdea(std::string idea, unsigned int index)
{
	this->brain->AppendIdea(idea,index);
}

void Dog::printIdea(void)
{
	this->brain->ShowIdea();
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Destructor Dog\n";
}