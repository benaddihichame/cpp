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


//////////////SETTER GETTER 


void	ClapTrap::setName(std::string name)
{
	this->name = name;
}
void	ClapTrap::setHitpoints(int x)
{
	this->HitPoints = x;
}
void	ClapTrap::setEnergiepoints( int x)
{
	this->EnergiePoints = x;
}
void	ClapTrap::setAttackdamage(int x)
{
	this->AttackDamage = x;
}

std::string ClapTrap::getName(void) const
{
	return this->name;
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return this->HitPoints;
}

unsigned int ClapTrap::getEnergiePoints(void) const
{
	return this->EnergiePoints;
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return this->AttackDamage;
}
		