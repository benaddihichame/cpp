#include "Intern.hpp"

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern &cpy)
{
	(void)cpy;
}
Intern &Intern::operator=(const Intern &cpy)
{
	(void)cpy;
	return *this;
}
AForm* Intern::makeForm(std::string name, std::string target)
{
	std::string formType[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
	AForm *form[3] = {new ShrubberyCreationForm(target), new RobotomyRequestForm(target), new PresidentialPardonForm(target)};

	for (int i = 0; i < 3; i++)
	{
		if (name == formType[i])
		{
			std::cout << "Intern creates " << formType[i] << std::endl;

			for (int j = 0; j < 3; j++)
			{
				if (j != i)
				{
					delete form[j];
				}
			}
			return (form[i]);
		}
	}
	for (int i =0; i < 3; i++)
	{
		delete form[i];
	}

	std::cout << "Error: This form -> " << name << " do not exist\n";
	return NULL; 
}
