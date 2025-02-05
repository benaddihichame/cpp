#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* k = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	k->makeSound();
	j->makeSound();
	meta->makeSound();

	delete k;
	delete j;
	delete meta;
	std::cout <<"\n\n";

    const WrongAnimal *i = new WrongCat();
    std::cout << "Type is : "<< i->getType() << std::endl;
    i->makeSound();
    delete i;
	return 0;
}