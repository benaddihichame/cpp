#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "\n=== TEST 1: Création du tableau d'animaux ===" << std::endl;
    const int numAnimals = 4;
    Animal* animals[numAnimals];

    std::cout << "\n--- Création des chiens ---" << std::endl;
    for (int i = 0; i < numAnimals / 2; i++) {
        animals[i] = new Dog();
        animals[i]->makeSound();  // Test du polymorphisme
    }

    std::cout << "\n--- Création des chats ---" << std::endl;
    for (int i = numAnimals / 2; i < numAnimals; i++) {
        animals[i] = new Cat();
        animals[i]->makeSound();  // Test du polymorphisme
    }

    std::cout << "\n=== TEST 2: Test de la copie profonde des Chats ===" << std::endl;
    {
        Cat* originalCat = new Cat();
        
        std::cout << "\n--- Ajout d'idées au chat original ---" << std::endl;
        originalCat->addIdea("Je veux du poisson", 0);
        originalCat->addIdea("Je veux dormir", 1);
        std::cout << "Idées du chat original:" << std::endl;
        originalCat->printIdea();

        std::cout << "\n--- Création d'une copie du chat ---" << std::endl;
        Cat* copyCat = new Cat(*originalCat);
        
        std::cout << "\n--- Modification du chat original ---" << std::endl;
        originalCat->addIdea("Nouvelle idée", 0);
        
        std::cout << "Idées du chat original après modification:" << std::endl;
        originalCat->printIdea();
        std::cout << "Idées de la copie:" << std::endl;
        copyCat->printIdea();

        delete originalCat;
        delete copyCat;
    }

    std::cout << "\n=== TEST 3: Test de l'opérateur d'assignation ===" << std::endl;
    {
        Cat firstCat;
        firstCat.addIdea("Première idée", 0);
        
        Cat secondCat;
        std::cout << "\n--- Assignation de firstCat à secondCat ---" << std::endl;
        secondCat = firstCat;  // Test de l'opérateur d'assignation
        
        std::cout << "Idées de secondCat après assignation:" << std::endl;
        secondCat.printIdea();
    }

    std::cout << "\n=== TEST 4: Nettoyage final ===" << std::endl;
    // Destruction de tous les animaux
    for (int i = 0; i < numAnimals; i++) {
        delete animals[i];
    }

    return 0;
}