#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequest", 72, 45), target("default")
{}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy):AForm(cpy), target(cpy.target)
{}
RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm("RobotomyRequest", 72, 45), target(target)
{}
RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
    if (this != &cpy)
    {
        AForm::operator=(cpy);
        this->target = cpy.target;
    }
    return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    if (!this->isSignedAForm())
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeRequiredToExec())
        throw AForm::GradeTooLowException();
    
    std::srand(std::time(NULL));

    std::cout << "* BZZZZZZ ... DRRRRRRRRR.... VRRRRRR ... BRRRR*\n";
    if (std::rand() % 2)
    {
        std::cout << this->target << " has been robotomized successfully!\n";
    }
    else
    {
        std::cout << "Robotomy of " << this->target << " Failed ;(\n";
    }
}