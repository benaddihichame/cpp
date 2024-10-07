/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:33:31 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/07 01:33:21 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}
PhoneBook::~PhoneBook() {}

void    PhoneBook::addContact()
{
	std::string input;
	Contact newContact;
	
    std::cout << "Enter Name :" <<std::endl;
	std::getline(std::cin, input);
	newContact.setName(input);
	std::cout << "Enter lastname :" <<std::endl;
	std::getline(std::cin, input);
	newContact.setLastName(input);
	std::cout << "Enter nickname :" <<std::endl;
	std::getline(std::cin, input);
	newContact.setNickname(input);
	std::cout << "Enter phone-number :" <<std::endl;
	std::getline(std::cin, input);
	newContact.setPhoneNumber(input);
	std::cout << "Enter dark secret :" <<std::endl;
	std::getline(std::cin, input);
	newContact.setDarkSecret(input);

	if (index < 8)
	{
		contact[index] = newContact;
		index++;
	}
	else
	{
		contact[index % 8] = newContact;
		index = (index + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

// void	PhoneBook::deleteContact()
// {
	
// }
void	PhoneBook::displayContact(Contact c)
{
	std::cout << "Name : " << c.getname() << std::endl;
	std::cout << "LastName : " << c.getlastName() << std::endl;
	std::cout << "Nickname : " << c.getnickname() << std::endl;
	std::cout << "Dark secret : " << c.getdarkSecret() << std::endl;
	std::cout << "Phone number : " << c.getphoneNumber() << std::endl;
}
void	PhoneBook::searchContact()
{
	int i = 0;
	if (index == 0)
	{
		std::cout << "Sad you have no friend :'(\n";
		return;
	}
	
	std::cout << "---------------LIST-------------------------" << std::endl;
    std::cout << "|  Index   |First Name| Last Name| Nickname |" << std::endl;
    std::cout << "|----------|----------|----------|----------|" << std::endl;

	while(i < index && i < 8)
	{
		std::cout << "|" << std::right << std::setw(10) << i + 1 << "|";
		std::cout << "|" << std::right << std::setw(10) << contact[i].getname();
		std::cout << "|" << std::right << std::setw(10) << contact[i].getlastName();
		std::cout << "|" << std::right << std::setw(10) << contact[i].getnickname() << "|";
		i++;
	}
	std::cout << "--------------------------------------------";
}