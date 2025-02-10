#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;
	
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat& other);
		Cat& operator=(const Cat& cpy);
		virtual void makeSound(void) const;
		void addIdea(std::string idea, unsigned int index);
		void printIdea(void);
		~Cat();
};


#endif