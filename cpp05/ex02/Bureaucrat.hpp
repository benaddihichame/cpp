#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>
#include "Form.hpp"

class Form;
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

	void signForm(Form &form);
	void canUpdateGrade(int NewGrade) const;
	void incrementGrade();
	void decrementGrade();
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);

#endif