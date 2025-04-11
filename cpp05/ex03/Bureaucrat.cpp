#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("No name"), grade(150)
{
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(std::string name, int grade):name(name)
{
	this->canUpdateGrade(grade);
	this->grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& cpy)
{
	*this = cpy;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& cpy)
{
	if (this != &cpy)
	{
		this->grade = cpy.getGrade();
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return this->name;
}
int	Bureaucrat::getGrade() const
{
	return this->grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high !";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low !";
}
void Bureaucrat::canUpdateGrade(int NewGrade) const
{
	if(NewGrade < 1)
	{
		throw GradeTooHighException();
	}
	else if (NewGrade > 150)
	{
		throw GradeTooLowException();
	}
}
void Bureaucrat::incrementGrade()
{
	this->canUpdateGrade(this->getGrade() - 1);
	this->grade--;
}
void Bureaucrat::decrementGrade()
{
	this->canUpdateGrade(this->getGrade() + 1);
	this->grade++;
}

void Bureaucrat::signForm(AForm &form)	
{
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form << std::endl;
	}catch (AForm::GradeTooLowException &e)
	{
		std::cerr << this->getName() << " couldn't sign " << form << " because " << e.what() << "." << std::endl;
	}

}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs)
{
	out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return out;
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " have execute " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " can't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}