#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain *brain;
	
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& other);
		Dog& operator=(const Dog& cpy);
		virtual void makeSound(void) const;
		void addIdea(std::string idea, unsigned int index);
		void printIdea(void);
		~Dog();
};


#endif