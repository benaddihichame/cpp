/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 02:03:30 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/17 15:20:21 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    ~Zombie();

    void    announce();
    void    setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);


#endif