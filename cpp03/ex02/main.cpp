#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Bob");
    FragTrap frag2(frag1); // Test du constructeur de copie
    FragTrap frag3;
    frag3 = frag1; // Test de l'opérateur d'affectation

    frag1.highFivesGuys(); // Test de la capacité spéciale
    frag1.attack("Target"); // Test de l'attaque
    frag1.takeDamage(20); // Test des dégâts
    frag1.beRepaired(10); // Test de la réparation

    return 0;
}