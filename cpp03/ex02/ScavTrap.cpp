#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default Constructor Called\n";
	this->setHitpoints(100);
	this->setEnergiepoints(50);
	this->setAttackdamage(20);
	this->guardmode = false;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "Default Constructor Called\n";
	this->setHitpoints(100);
	this->setEnergiepoints(50);
	this->setAttackdamage(20);
	this->guardmode = false;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "Copy constructor called for" << other.getName() << std::endl;
	*this = other;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& cpy)
{
	if (&cpy != this)
	{
		this->setName(cpy.getName());
		this->setHitpoints(cpy.getHitPoints());
		this->setEnergiepoints(cpy.getEnergiePoints());
		this->setAttackdamage(cpy.getAttackDamage());
		this->guardmode = cpy.guardmode;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() <<  " cant attack because he have no hitpoint\n";
		return;
	}
	if (this->getEnergiePoints() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() <<  " cant attack because he have no energie\n";
		return;
	}
	std::cout << "ScavTrap " << this->getName() << " attack " << target << " and deal " << this->getAttackDamage() << std::endl;
	this->setEnergiepoints(this->getEnergiePoints() - 1);
}

void	ScavTrap::guardGate()
{
	if (this->guardmode == true)
	{
		std::cout << "ScavTrap " << this->getName() << " Is already in guardmode\n";
		return;
	}
	else
	{
		std::cout << "ScavTrap " << this->getName() << " Is now in guardmode\n";
		this->guardmode = true;
		return;
	}
}
void	ScavTrap::setGuardMode(bool mode)
{
	this->guardmode = mode;
}
bool	ScavTrap::getGuardMode()
{
	return this->guardmode;
}