/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:03:46 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/02 20:07:47 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


Contact::Contact(void)
{
    return ;
}

Contact::~Contact()
{
    return ;
}
std::string Contact::getname(void) const
{
    return this->name;
}

std::string Contact::getlastName(void) const
{
    return this->lastName;
}

std::string Contact::getnickname() const
{
    return this->nickname;
}