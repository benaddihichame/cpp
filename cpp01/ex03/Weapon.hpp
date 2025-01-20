/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 17:13:25 by hbenaddi          #+#    #+#             */
/*   Updated: 2025/01/15 09:12:32 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon(std::string type);
		~Weapon();
		std::string	getType(void) const;
		void setType(std::string newType);
	private :
		std::string type;
	
};

#endif