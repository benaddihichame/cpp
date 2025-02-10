#include "Cat.hpp"

Cat::Cat() : Animal("Cat") 
{
	this->brain = new Brain();
	std::cout << "Im the Default constructor of Cat\n" ;
}

Cat::Cat(std::string type) : Animal(type)
{
	this->type = type;
	this->brain = new Brain();
	std::cout << "ARGS Constructor for " <<  type  << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{	
	std::cout << "Constructor COPY Cat\n";
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& cpy)
{
	if (&cpy != this)
	{
		this->type = cpy.type;
		this->brain = new Brain(*cpy.brain);
	}
	std::cout << "Operator assignation Cat\n";
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Im a Cat Miaou Miaou\n" ;
}

void Cat::addIdea(std::string idea, unsigned int index)
{
	this->brain->AppendIdea(idea, index);
}

void Cat::printIdea()
{
	this->brain->ShowIdea();
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Destructor Cat\n";
}