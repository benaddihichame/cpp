#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int	main(void)
{
	Bureaucrat lowRank("Intern", 140);
	Bureaucrat midRank("Officer", 70);
	Bureaucrat highRank("Director", 4);

	std::cout << "--- Bureaucrats Created ---" << std::endl;
	std::cout << lowRank;
	std::cout << midRank;
	std::cout << highRank;
	std::cout << std::endl;

	std::cout << "--- Testing ShrubberyCreationForm ---" << std::endl;
	ShrubberyCreationForm shrubForm("garden");

	std::cout << "Attempt to execute before signing:" << std::endl;
	try
	{
		lowRank.executeForm(shrubForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "Intern attempts to sign (should work):" << std::endl;
	lowRank.signForm(shrubForm);

	std::cout << "Intern attempts to execute (should work):" << std::endl;
	lowRank.executeForm(shrubForm);
	std::cout << std::endl;

	std::cout << "--- Testing RobotomyRequestForm ---" << std::endl;
	RobotomyRequestForm robotForm("Bender");

	std::cout << "Intern attempts to sign (should fail):" << std::endl;
	lowRank.signForm(robotForm);

	std::cout << "Officer attempts to sign (should work):" << std::endl;
	midRank.signForm(robotForm);

	std::cout << "Intern attempts to execute (should fail):" << std::endl;
	lowRank.executeForm(robotForm);

	std::cout << "Officer attempts to execute (should work):" << std::endl;
	midRank.executeForm(robotForm);
	std::cout << std::endl;

	std::cout << "--- Testing PresidentialPardonForm ---" << std::endl;
	PresidentialPardonForm pardonForm("Arthur Dent");

	std::cout << "Officer attempts to sign (should fail):" << std::endl;
	midRank.signForm(pardonForm);

	std::cout << "Director attempts to sign (should work):" << std::endl;
	highRank.signForm(pardonForm);

	std::cout << "Officer attempts to execute (should fail):" << std::endl;
	midRank.executeForm(pardonForm);

	std::cout << "Director attempts to execute (should work):" << std::endl;
	highRank.executeForm(pardonForm);
	std::cout << std::endl;

	return (0);
}