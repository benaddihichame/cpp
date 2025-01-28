#include "ClapTrap.hpp"

int main()
{
	ClapTrap robot("R2D2");
    
    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(8);
    robot.attack("Enemy");
    robot.beRepaired(5); 

}