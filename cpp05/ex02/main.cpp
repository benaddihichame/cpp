#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);
		Form tax("Tax Form", 100, 50);
		Form security("Security Clearance", 5, 2);

		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
		std::cout << tax << std::endl;
		std::cout << security << std::endl;

		boss.signForm(tax);
		boss.signForm(security);

		intern.signForm(tax);
		Form invalid1("Invalid", 0, 50);
	}catch (std::exception &e)
	{
		std::cout <<"Execption: " << e.what() << std::endl;
	}
	try {
		Form invalid2("INvalid2", 151, 50);
	}catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}