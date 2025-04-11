#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &cpy);
		AForm *makeForm(std::string name, std::string target);
};
#endif