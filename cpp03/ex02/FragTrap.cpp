#include "FragTrap.hpp"


FragTrap::FragTrap()
{
	std::cout << "FragTrap Default Constructor FragTrap\n";
	this->setAttackdamage(100);
	this->setEnergiepoints(100);
	this->setHitpoints(30);
}
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap String Constructor FragTrap for "<< this->getName() << std::endl;
	this->setAttackdamage(100);
	this->setEnergiepoints(100);
	this->setHitpoints(30);
}

FragTrap::FragTrap(const FragTrap& cpy)
{
	std::cout << "FragTrap Copy constructor called for " << cpy.getName() << std::endl;
	*this = cpy;
}


FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->setAttackdamage(other.getAttackDamage());
		this->setEnergiepoints(other.getEnergiePoints());
		this->setHitpoints(other.getHitPoints());
		this->setName(other.getName());
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->getName() << " High Five?\n";
}