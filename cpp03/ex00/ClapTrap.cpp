#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
: name("Default"), HitPoints(10) , EnergiePoints(10), AttackDamage(0)
{
	std::cout << "Default Constructor Called\n";
}

ClapTrap::ClapTrap(std::string name)
: name(name), HitPoints(10) , EnergiePoints(10) , AttackDamage(0)
{
	std::cout << "Constructor string called\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Constructor copy called\n";
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &cpy)
{
	if (this != &cpy)
	{
		this->name = cpy.name;
		this->HitPoints = cpy.HitPoints;
		this->AttackDamage = cpy.AttackDamage;
		this->EnergiePoints = cpy.EnergiePoints;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor Called\n";
}

///////////////////////////////////////////////////////////////////

void ClapTrap::attack(const std::string& target)
{
	if (this->EnergiePoints > 0 && this->HitPoints > 0)
	{
		this->EnergiePoints--;
		std::cout << "ClapTrap " << this->name << " atack " << target << " dealing " << this->AttackDamage << " damage\n";
	}
	else
		std::cout << "ClapTrap " << this->name << " can't attack\n";
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->HitPoints < 0)
	{
		std::cout << "ClapTrape " << this->name << " Don t have any hitpoint left\n";
		return ;
	}
	if (this->HitPoints > amount)
		this->HitPoints -= amount;
	else
		this->HitPoints = 0;
	std::cout << this->name << " take " << amount << " damage he have " << this->HitPoints << " hitpoint left\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EnergiePoints <= 0)
	{
		std::cout << "Claptrap " << this->name << " have no fuel to be repaire\n"; 
		return ;
	}
	if (this->HitPoints <= 0)
	{
		std::cout << "Claptrap " << this->name << " is too damaged to be repaire\n"; 
		return ;
	}
	this->HitPoints += amount;
	this->EnergiePoints--;
	std::cout << "Claptrap repared his Hitpoint : " << this->HitPoints << std::endl;
}