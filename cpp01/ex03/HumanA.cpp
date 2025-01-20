/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:13:09 by hbenaddi          #+#    #+#             */
/*   Updated: 2025/01/15 09:15:10 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &gun) : gun(gun)
{
	this->name = name;
	std::cout << "HumanA constructor was called" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destructor was called" << std::endl;
}
std::string	HumanA::getName()
{
	return this->name;
}

void	HumanA::attack()
{
	std::cout << this->name << " attack with " << this->gun.getType() << std::endl;
}