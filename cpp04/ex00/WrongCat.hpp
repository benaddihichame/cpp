#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>

class WrongCat 
{
	public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat& other);
	WrongCat& operator=(const WrongCat& cpy);
	virtual ~WrongCat();
	virtual void makeSound(void) const;
};


#endif