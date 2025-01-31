#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap Default Constructor FragTrap\n";
	this->name = "UnNamedd";
	this->AttackDamage = 30;
	this->EnergiePoints = 100;
	this->HitPoints = 100;
}
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->name = name;
	this->AttackDamage = 30;
	this->EnergiePoints = 100;
	this->HitPoints = 100;
	std::cout << "FragTrap String Constructor FragTrap for "<< this->name << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap Copy constructor called for " << cpy.name << std::endl;
	*this = cpy;
}


FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		this->AttackDamage = other.AttackDamage;
		this->EnergiePoints = other.EnergiePoints;
		this->HitPoints = other.HitPoints;
		this->name = other.name;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << this->name << " High Five?\n";
}