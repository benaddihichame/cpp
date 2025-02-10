#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal 
{
	protected:
		std::string type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& other);
		AAnimal& operator=(const AAnimal& cpy);
		virtual ~AAnimal();
		virtual void makeSound(void) const = 0;
		std::string getType() const;
};


#endif