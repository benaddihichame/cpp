#include "AForm.hpp"

AForm::AForm(): name("default"), sign(false), grade_sign(150), grade_exec(150){}
AForm::~AForm(){}
AForm::AForm(const AForm&cpy): name(cpy.name), sign(false), grade_sign(cpy.grade_sign), grade_exec(cpy.grade_exec){}


AForm::AForm(std::string name,int grade_sign, int grad_exec): name(name), sign(false), grade_sign(grade_sign), grade_exec(grad_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grad_exec > 150)
		throw AForm::GradeTooLowException();
}
std::string AForm::getName() const
{
	return this->name;
}

bool AForm::isSignedAForm()
{
	return this->sign;
}
int AForm::getGradeRequiredToSign()const
{
	return this->grade_sign;
}

int AForm::getGradeRequiredToExec()const
{
	return this->grade_exec;
}


void AForm::beSigned(Bureaucrat& pion)
{
	if(pion.getGrade() <= this->grade_sign)
	{
		this->sign = true;
	}
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high !";
}
const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low !";
}


std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << form.getName();
	return os;
}