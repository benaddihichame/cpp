#include "ScavTrap.hpp"

int main()
{
    // Test des constructeurs
    std::cout << "\n=== Test des constructeurs ===\n";
    ClapTrap default_clap;
    ClapTrap clap("R2D2");
    ScavTrap default_scav;
    ScavTrap scav("R3D3");

    // Test de copie
    std::cout << "\n=== Test de copie ===\n";
    ClapTrap clap_copy(clap);
    ScavTrap scav_copy(scav);

    // Test des attaques ClapTrap
    std::cout << "\n=== Test des attaques ClapTrap ===\n";
    clap.attack("Target1");
    clap.takeDamage(5);
    clap.beRepaired(3);
    
    // Vérification des points après dégâts
    std::cout << "\nPoints de " << clap.getName() << " après combat:\n";
    std::cout << "Hit points: " << clap.getHitPoints() << std::endl;
    std::cout << "Energie points: " << clap.getEnergiePoints() << std::endl;

    // Test des attaques ScavTrap
    std::cout << "\n=== Test des attaques ScavTrap ===\n";
    scav.attack("Target2");
    scav.takeDamage(30);
    scav.beRepaired(20);

    // Test du mode Guard
    std::cout << "\n=== Test du mode Guard ===\n";
    scav.guardGate();
    std::cout << "Guard mode is " << (scav.getGuardMode() ? "ON" : "OFF") << std::endl;

    // Test de dépassement d'énergie
    std::cout << "\n=== Test de dépassement d'énergie ===\n";
    for (int i = 0; i < 52; i++)
    {
        scav.attack("Dummy Target");
    }

    // Test de mort
    std::cout << "\n=== Test de mort ===\n";
    scav.takeDamage(200);
    scav.attack("Target");
    scav.beRepaired(50);

    std::cout << "\n=== Fin des tests ===\n";
    return 0;
}