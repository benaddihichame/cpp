#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int	HitPoints  = 10;
		int	EnergiePoints = 10;
		int	AttackDamage = 0;
	public:
		ClapTrap();
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif