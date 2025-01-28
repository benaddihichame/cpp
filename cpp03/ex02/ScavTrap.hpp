#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
	bool guardmode;

	public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& cpy);
	~ScavTrap();

	void attack(const std::string& target);
	void	guardGate();
	void	setGuardMode(bool mode);
	bool	getGuardMode();
};

#endif