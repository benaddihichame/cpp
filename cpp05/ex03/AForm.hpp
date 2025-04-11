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
	public:
		AForm();
		virtual ~AForm();
		AForm(const AForm&cpy);
		AForm(std::string name,int grade_sign, int grad_exec);
		AForm &operator=(const AForm&cpy);
		std::string getName() const;
		void beSigned(Bureaucrat& pion);
		bool isSignedAForm()const;
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
		class NotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw();
		};


		virtual void execute(const Bureaucrat &executor) const = 0;
};
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif