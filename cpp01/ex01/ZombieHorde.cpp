/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:06:29 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/17 15:03:24 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name)
{
    Zombie* horde = new Zombie[N];
    int index = 0;
    while (index < N)
    {
        horde[index].setName(name);
        index++;
    }
    return horde;
}