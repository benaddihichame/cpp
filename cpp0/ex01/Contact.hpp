/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenaddi <hbenaddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:04:00 by hbenaddi          #+#    #+#             */
/*   Updated: 2024/10/02 15:41:15 by hbenaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
        std::string name;
        std::string nickName;
        std::string lastName;
        std::string phoneNumber;
        std::string darkSecret;
public:
        Contact(void);
        ~Contact(void);
        void    init(void);
        void setName(std::string n);
        std::string getName();
};

#endif