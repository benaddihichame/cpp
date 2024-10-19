/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:39:16 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/17 01:51:54 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}
Zombie::~Zombie()
{
    std::cout << this->name << " is Dead again\n";
}

void    Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";   
}