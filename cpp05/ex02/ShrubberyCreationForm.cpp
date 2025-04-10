#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreation", 145, 137), target("default")
{}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy):AForm(cpy), target(cpy.target)
{}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreation", 145, 137), target(target)
{}
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
    if (this != &cpy)
    {
        AForm::operator=(cpy);
        this->target = cpy.target;
    }
    return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!this->isSignedAForm())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeRequiredToExec())
		throw AForm::GradeTooLowException();

	std::string filename = this->target + "_shrubbery";
	std::ofstream outfile(filename.c_str());

	if (!outfile.is_open())
		throw std::runtime_error("Could not open file for writing");

    outfile << "    *    " << std::endl;
    outfile << "   ***   " << std::endl;
    outfile << "  *****  " << std::endl;
    outfile << " ******* " << std::endl;
    outfile << "*********" << std::endl;
    outfile << "    |    " << std::endl;
    outfile << "    |    " << std::endl;
    outfile << std::endl;

    outfile << "      /\\      " << std::endl;
    outfile << "     /\\/\\     " << std::endl;
    outfile << "    /\\/\\/\\    " << std::endl;
    outfile << "   /\\/\\/\\/\\   " << std::endl;
    outfile << "  /\\/\\/\\/\\/\\  " << std::endl;
    outfile << "     |||      " << std::endl;
    outfile << "     |||      " << std::endl;
    outfile << std::endl;

    outfile << "    ,.,    " << std::endl;
    outfile << "   MMMMM   " << std::endl;
    outfile << "  MMMMMMM  " << std::endl;
    outfile << " MMMMMMMMM " << std::endl;
    outfile << "MMMMMMMMMMM" << std::endl;
    outfile << "    |||    " << std::endl;
    outfile << "    |||    " << std::endl;

	outfile.close();
}