/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:06:35 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/17 15:22:43 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int j = 0;
    int i = 5;

    Zombie* horde = zombieHorde(i, "BrainDead");
    
    while (j < i)
    {
        horde[j].announce();
        j++;    
    }
    
    delete[] horde;
}