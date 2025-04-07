#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_exec;
		AForm();
	public:
		~AForm();
		AForm(const AForm&cpy);
		AForm(std::string name,int grade_sign, int grad_exec);
		AForm &operator=(const AForm&cpy);
		std::string getName() const;
		void beSigned(Bureaucrat& pion);
		bool isSignedAForm();
		int getGradeRequiredToSign()const;
		int getGradeRequiredToExec()const;

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif