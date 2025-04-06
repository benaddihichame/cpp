#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
	private:
		const std::string name;
		bool sign;
		const int grade_sign;
		const int grade_exec;
		Form();
		Form &operator=(const Form&cpy);
	public:
		~Form();
		Form(const Form&cpy);
		Form(std::string name,int grade_sign, int grad_exec);
		std::string getName() const;
		void beSigned(Bureaucrat& pion);
		bool isSignedForm();
		int getGradeRequiredToSign()const;
		int getGradeRequiredToExec()const;
};

#endif