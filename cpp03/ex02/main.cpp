#include "FragTrap.hpp"

int main()
{
    FragTrap frag1("Bob");
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag1;

    frag1.highFivesGuys();
    frag1.attack("Target");
    frag1.takeDamage(20);
    frag1.beRepaired(10);

    return 0;
}