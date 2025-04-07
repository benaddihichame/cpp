#include "Form.hpp"

Form::Form(): name("default"), sign(false), grade_sign(150), grade_exec(150){}
Form::~Form(){}
Form::Form(const Form&cpy): name(cpy.name), sign(false), grade_sign(cpy.grade_sign), grade_exec(cpy.grade_exec){}


Form::Form(std::string name,int grade_sign, int grad_exec): name(name), sign(false), grade_sign(grade_sign), grade_exec(grad_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw Form::GradeTooHighException();
	if (grade_sign > 150 || grad_exec > 150)
		throw Form::GradeTooLowException();
}
std::string Form::getName() const
{
	return this->name;
}

bool Form::isSignedForm()
{
	return this->sign;
}
int Form::getGradeRequiredToSign()const
{
	return this->grade_sign;
}

int Form::getGradeRequiredToExec()const
{
	return this->grade_exec;
}


void Form::beSigned(Bureaucrat& pion)
{
	if(pion.getGrade() <= this->grade_sign)
	{
		this->sign = true;
	}
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high !";
}
const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low !";
}


std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << form.getName();
	return os;
}