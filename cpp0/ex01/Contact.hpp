/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:04:00 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/02 19:40:24 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
        std::string name;
        std::string nickname;
        std::string lastName;
        std::string phoneNumber;
        std::string darkSecret;
        int index;
public:
        Contact(void);
        ~Contact(void);
        
        std::string     getname(void) const;
        std::string     getlastName(void) const;
        std::string     getnickname(void) const;
        std::string     getphoneNumber(void) const;
        std::string     getdarkSecret(void) const;
        int     getIndex(void)const;


        void setName(std::string name);
        void setNickname(std::string nickname);
        void setLastName(std::string lastName);
        void setPhoneNumber(std::string PhoneNumber);
        void setDarkSecret(std::string darkSecret);
        void setIndex(int index);
};

#endif