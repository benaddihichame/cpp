#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>
#include "AForm.hpp"
class AForm;
class Bureaucrat
{
	private:
	const std::string name;
	int	grade;
	public:

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

	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& cpy);
	Bureaucrat& operator=(const Bureaucrat& cpy);
	
	std::string getName() const;
	int	getGrade() const;

	void signForm(AForm &form);
	void canUpdateGrade(int NewGrade) const;
	void incrementGrade();
	void decrementGrade();
	void executeForm(AForm const & form);
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif