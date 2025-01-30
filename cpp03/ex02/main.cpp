#include "FragTrap.hpp"

int main()
{
    // Test des constructeurs et de la copie
    std::cout << "\n=== Test des constructeurs et copies ===\n";
    FragTrap frag1("Bob");                   // Test du constructeur avec nom
    FragTrap frag2(frag1);                   // Test du constructeur de copie
    FragTrap frag3;                          // Test du constructeur par défaut
    frag3 = frag1;                           // Test de l'opérateur d'affectation

    // Affichage des statistiques initiales
    std::cout << "\n=== Statistiques initiales ===\n";
    std::cout << "Bob's stats - HP: " << frag1.getHitPoints() 
              << " EP: " << frag1.getEnergiePoints() 
              << " AD: " << frag1.getAttackDamage() << std::endl;

    // Test des capacités spéciales
    std::cout << "\n=== Test des capacités spéciales ===\n";
    frag1.highFivesGuys();
    frag2.highFivesGuys();

    // Test des combats
    std::cout << "\n=== Test des mécaniques de combat ===\n";
    // Multiple attaques pour tester la consommation d'énergie
    for (int i = 0; i < 5; i++) {
        frag1.attack("Dragon");
    }

    // Test des dégâts et réparations
    std::cout << "\n=== Test des dégâts et réparations ===\n";
    frag1.takeDamage(50);                    
    frag1.beRepaired(20);                   
    frag1.takeDamage(30);                   

    // Test des limites
    std::cout << "\n=== Test des situations limites ===\n";
    // Test de mort
    frag1.takeDamage(200);                   
    frag1.attack("Target");                 
    frag1.beRepaired(50);                   

    // Test d'épuisement d'énergie
    std::cout << "\n=== Test d'épuisement d'énergie ===\n";
    for (int i = 0; i < 102; i++) {          
        frag2.attack("Dummy");
    }
    frag2.beRepaired(10);                   
    frag2.highFivesGuys();                  

    std::cout << "\n=== Fin des tests ===\n";
    return 0;
}