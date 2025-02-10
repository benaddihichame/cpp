#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default constructor Called\n";
}
Brain::Brain(const Brain& other)
{
	*this = other;
	std::cout << "Brain Copy constructor Called\n";
}
Brain& Brain::operator=(const Brain& cpy)
{
	if(&cpy != this)
	{
		for (int i = 0; i < 100; i++)
            this->ideas[i] = cpy.ideas[i];
	}
	std::cout << "Brain assignation operator Called\n";
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor Called\n";
}

void Brain::AppendIdea(const std::string &idea, unsigned int num)
{
	if(num >= 100)
		return;
	this->ideas[num] = idea;
}

void	Brain::ShowIdea()
{
	int i =0;
	while(i < 100)
	{
		if(!this->ideas[i].empty())
			std::cout << i << ": " << this->ideas[i] << std::endl;
		i++;
	}
}