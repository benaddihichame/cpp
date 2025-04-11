#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern someRandomIntern;
	Bureaucrat boss("Big Boss", 1);

	std::cout << "--- Testing valid form creation ---" << std::endl;

	AForm *rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	AForm *scf = someRandomIntern.makeForm("ShrubberyCreation", "garden");
	if (scf)
	{
		std::cout << *scf << std::endl;
		boss.signForm(*scf);
		boss.executeForm(*scf);
		delete scf;
	}

	AForm *ppf = someRandomIntern.makeForm("PresidentialPardon",
			"Douglas Adams");
	if (ppf)
	{
		std::cout << *ppf << std::endl;
		boss.signForm(*ppf);
		boss.executeForm(*ppf);
		delete ppf;
	}

	std::cout << "\n--- Testing invalid form creation ---" << std::endl;

	AForm *nonExistentForm = someRandomIntern.makeForm("coffee making",
			"break room");
	if (nonExistentForm)
	{
		std::cout << "This should not print!" << std::endl;
		delete nonExistentForm;
	}
	else
	{
		std::cout << "Form creation failed as expected." << std::endl;
	}

	return (0);
}