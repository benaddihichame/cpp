/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:01:02 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/02 15:30:36 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook
{
private:
        Contact contact[8];
        int index;
        int max;
public:
        PhoneBook()
        {
            index = 0;
            max = 8;
        }
        ~PhoneBook();
        void    addContact();
        void    deleteContact();
        void    searchContact();

};

#endif