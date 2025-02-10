#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& cpy);
	~WrongCat();
	void makeSound(void) const;
};


#endif