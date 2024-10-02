/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:01:02 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/02 18:52:47 by hbenaddi         ###   ########.fr       */
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
        int max = 8;
public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    deleteContact();
        void    searchContact();
};

#endif