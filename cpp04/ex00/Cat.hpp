#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
	Cat();
	Cat(std::string type);
	Cat(const Cat& other);
	Cat& operator=(const Cat& cpy);
	virtual void makeSound(void) const;
	~Cat();
};


#endif