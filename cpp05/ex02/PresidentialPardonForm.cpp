#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardon", 25, 5), target("default")
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy):AForm(cpy), target(cpy.target)
{}
PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm("PresidentialPardon", 25, 5), target(target)
{}
PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
    if (this != &cpy)
    {
        AForm::operator=(cpy);
        this->target = cpy.target;
    }
    return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSignedAForm())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeRequiredToExec())
        throw AForm::GradeTooLowException();
    std::cout << this->target << " has been pardoned by Zaphod beeblebrox.\n";
}