/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:01:02 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/05 14:41:15 by hbenaddi         ###   ########.fr       */
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
public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    deleteContact();
        void    searchContact();
        void    displayContact(Contact c);
};

#endif