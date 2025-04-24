#include "MutantStack.hpp"
int main()
{
    std::cout << "[1] Création d'un MutantStack..." << std::endl;
    MutantStack<int> mstack;

    std::cout << "[2] On push 5" << std::endl;
    mstack.push(5);

    std::cout << "[3] On push 17" << std::endl;
    mstack.push(17);

    std::cout << "[4] On affiche le top : ";
    std::cout << mstack.top() << std::endl;

    std::cout << "[5] On pop le top (17)" << std::endl;
    mstack.pop();

    std::cout << "[6] On affiche la taille après pop : ";
    std::cout << mstack.size() << std::endl;

    std::cout << "[7] On push 3, puis 5, puis 737..." << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    std::cout << "[8] On push 0" << std::endl;
    mstack.push(0);

    std::cout << "[9] Début de l'itération sur le MutantStack :" << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "On incrémente l'iterator (++it)" << std::endl;
    ++it;
    std::cout << "On décrémente l'iterator (--it)" << std::endl;	
    --it;

    std::cout << "Affichage de toutes les valeurs dans la stack :" << std::endl;
    while (it != ite)
    {
        std::cout << "Valeur : " << *it << std::endl;
        ++it;
    }
	std::stack<int> s(mstack);
	return 0;
}