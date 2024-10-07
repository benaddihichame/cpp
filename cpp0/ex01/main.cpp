/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:03:21 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/07 18:44:10 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

void    showHome()
{
    std::cout << "**********************************************" << std::endl;
    std::cout << "*          \033[5;31mWelcome to Hichome phoneBook\033[0m      *" << std::endl;
    std::cout << "*                                            *" << std::endl;
    std::cout << "**********************************************" << std::endl;
    std::cout << "Menu:" << std::endl;
    std::cout << "> \033[38;5;226mADD\033[0m📲    : Add a new contact" << std::endl;
    std::cout << "> \033[38;5;226mSEARCH\033[0m🔎 : Search for a contact" << std::endl;
    std::cout << "> \033[38;5;226mEXIT\033[0m📵  : Exit the PhoneBook" << std::endl;
    std::cout << "**********************************************" << std::endl;
}
int main()
{
    std::string commande;
    PhoneBook Phone;
    
    showHome();
    while(1)
    {
        std::cout << "->";
        std::getline(std::cin, commande);
        if (std::cin.eof())
            break;
        else if (commande == "ADD")
            Phone.addContact();
        else if (commande == "SEARCH")
           Phone.searchContact();
        else if (commande == "EXIT")
            break;
        else if (commande.empty())
        {
            std::cout<< "Comon men You just had to press the good boutton\n";
            continue;
        }
        else
            std::cout<< "ONLY ENTER ADD EXIT OR SEARCH\n";
    }
    return (0);
}