#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	std::cout << "HumanB constructor was called" << std::endl;
	this->name = name;
}
HumanB::~HumanB()
{
	std::cout << "HumanB destructor was called" << std::endl;
}
std::string HumanB::getName(void)
{
	return this->name;
}

void	HumanB::setWeapon(Weapon &gun)
{
	this->gun = &gun;
}

void HumanB::attack()
{
    if (this->gun)
        std::cout << this->name << " attacks with their " << this->gun->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack with" << std::endl;
}
