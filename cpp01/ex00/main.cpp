/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:25:34 by hbenaddi          #+#    #+#             */
/*   Updated: 2025/01/17 15:02:22 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *ko;

    ko = newZombie("Zombiesansbuzz");
    ko->announce();
    randomChump("foo");
    delete ko;
}