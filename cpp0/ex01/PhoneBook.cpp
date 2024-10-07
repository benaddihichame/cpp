/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:33:31 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/07 18:45:30 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream> 
#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0) {}
PhoneBook::~PhoneBook() {}


std::string	truncate(const std::string& str)
{
	if(str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}
void    PhoneBook::addContact()
{
	std::string input;
	Contact newContact;
	
    std::cout << "Enter FirstName :" <<std::endl;
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout<< "Don't handle empty\n";
		return ;
	}
	newContact.setName(input);
	std::cout << "Enter lastname :" <<std::endl;
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout<< "Don't handle empty\n";
		return ;
	}
	newContact.setLastName(input);
	std::cout << "Enter nickname :" <<std::endl;
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout<< "Don't handle empty\n";
		return ;
	}
	newContact.setNickname(input);
	std::cout << "Enter phone-number :" <<std::endl;
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout<< "Don't handle empty\n";
		return ;
	}
	newContact.setPhoneNumber(input);
	std::cout << "Enter dark secret :" <<std::endl;
	std::getline(std::cin, input);
	if(input.empty())
	{
		std::cout<< "Don't handle empty\n";
		return ;
	}
	newContact.setDarkSecret(input);

	if (index < 8)
	{
		contact[index] = newContact;
		index++;
	}
	else
	{
		contact[index % 8] = newContact;
		index = (index + 1);
	}
    std::cout << "\033[32mContact added successfully!\033[0m" << std::endl;
}
void	PhoneBook::displayContact(Contact c)
{
	std::cout << "FirstName : " << c.getname() << std::endl;
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
		std::cout << "|" << std::right << std::setw(10) << i + 1;
		std::cout << "|" << std::right << std::setw(10) << truncate(contact[i].getname());
		std::cout << "|" << std::right << std::setw(10) << truncate(contact[i].getlastName());
		std::cout << "|" << std::right << std::setw(10) << truncate(contact[i].getnickname()) << "|\n";
		i++;
	}
	std::cout << "--------------------------------------------\n";
 
	std::cout << "\nEnter the Index of your friend to see the information :";
	int pos;
	std::string input;

	std::getline(std::cin, input);
	std::istringstream(input) >> pos;
	if (pos >= 1 && pos < 8)
		displayContact(contact[pos - 1]);
	else
		std::cout << "enter a good index\n";
}