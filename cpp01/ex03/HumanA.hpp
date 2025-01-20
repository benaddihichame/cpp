#ifndef HUMANA
# define  HUMANA

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
	private:
	std::string	name;
	Weapon &gun;

	public:
		HumanA(std::string name, Weapon &gun);
		~HumanA();

		std::string	getName(void);
		void	attack(void);
};


#endif