#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>
class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);

		void	execute(const Bureaucrat &executor) const;
};

#endif