#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default Constructor Called\n";
	this->name = "UnNamed";
	this->HitPoints = 100;
	this->EnergiePoints = 50;
	this->AttackDamage = 20;
	this->guardmode = false;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap String Constructor Called\n";
	this->name = name;
	this->HitPoints = 100;
	this->EnergiePoints = 50;
	this->AttackDamage = 20;
	this->guardmode = false;
}
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called for " << other.name << std::endl;
	*this = other;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& cpy)
{
	if (&cpy != this)
	{
		this->HitPoints = cpy.HitPoints;
		this->EnergiePoints = cpy.EnergiePoints;
		this->AttackDamage = cpy.AttackDamage;
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
	if (this->HitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name <<  " cant attack because he have no hitpoint\n";
		return;
	}
	if (this->EnergiePoints <= 0)
	{
		std::cout << "ScavTrap " << this->name <<  " cant attack because he have no energie\n";
		return;
	}
	std::cout << "ScavTrap " << this->name << " attack " << target << " and deal " << this->AttackDamage << std::endl;
	this->EnergiePoints--;
}

void	ScavTrap::guardGate()
{
	if (this->guardmode == true)
	{
		std::cout << "ScavTrap " << this->name << " Is already in guardmode\n";
		return;
	}
	else
	{
		std::cout << "ScavTrap " << this->name << " Is now in guardmode\n";
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