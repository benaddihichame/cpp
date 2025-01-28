#ifndef CLAPTRAP_H
# define CLAPTRAP_H
# include <iostream>

class ClapTrap
{
	private:
		std::string name;
		unsigned int	HitPoints;
		unsigned int	EnergiePoints;
		unsigned int	AttackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &cpy);

		void	setName(std::string name);
		void	setHitpoints(int x);
		void	setEnergiepoints( int x);
		void	setAttackdamage(int x);

		std::string getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergiePoints(void) const;
		unsigned int getAttackDamage(void) const;

		~ClapTrap();

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif