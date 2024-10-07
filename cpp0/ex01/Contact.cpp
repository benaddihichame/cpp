/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:03:46 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/06 15:54:03 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::getname(void) const
{
    return name;
}

std::string Contact::getlastName(void) const
{
    return lastName;
}

std::string Contact::getnickname() const
{
    return nickname;
}

std::string Contact::getdarkSecret()const
{
    return darkSecret;
}

std::string Contact::getphoneNumber()const
{
    return phoneNumber;
}

int Contact::getIndex()const
{
    return index;
}

void Contact::setDarkSecret(std::string darkSecret)
{
    this->darkSecret = darkSecret;
}
void Contact::setIndex(int index)
{
    this->index = index;
}
void Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}
void Contact::setName(std::string name)
{
    this->name = name;
}
void Contact::setNickname(std::string nickname)
{
    this->nickname = nickname;
}
void Contact::setPhoneNumber(std::string PhoneNumber)
{
    this->phoneNumber = phoneNumber;
}