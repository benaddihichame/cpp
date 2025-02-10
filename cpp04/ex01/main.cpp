#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const int size = 6;

	Animal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i < size / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
		delete animals[i];

    Dog dog;
    Cat cat;
    
    dog.makeSound();
    cat.makeSound();

    // Test deep copy
    dog.addIdea("I love bones", 0);
    dog.addIdea("I want to play", 1);
    
    Dog dog2(dog);
    dog.addIdea("i love pas bonne", 0);
    dog.printIdea();
    dog2.printIdea();

    return 0;
}