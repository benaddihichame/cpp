#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class	HumanB
{
	private :
	std::string name;
	Weapon *gun;
	public :
	HumanB(std::string name);
	~HumanB();

	std::string	getName(void);
	void	setWeapon(Weapon &gun);
	void	attack(void);

};

#endif