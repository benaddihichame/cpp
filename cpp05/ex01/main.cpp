#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat yoyo("over", 151);
		std::cout << yoyo << std::endl;
	} catch (std::exception &e){
		std::cerr << "'Over': " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		Bureaucrat yaya("normal", 20);
		std::cout << yaya << std::endl;
	}catch(std::exception &e){
		std::cerr << "'normal': " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try{
		Bureaucrat yiyi("high", 0);
		std::cout << yiyi << std::endl;
	}catch(std::exception &e){
		std::cerr << "'yiyi': " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		Bureaucrat sup("sup", 3);
		std::cout <<sup << std::endl;
		sup.incrementGrade();
		std::cout <<sup << std::endl;
	}catch(std::exception &e)
	{
		std::cerr << "'supp': "<< e.what() << std::endl;
	}
	std::cout << std::endl;

	try{
		Bureaucrat inf("inf", 149);
		std::cout <<inf << std::endl;
		inf.decrementGrade();
		std::cout <<inf << std::endl;
		inf.decrementGrade();
		std::cout <<inf << std::endl;
	}catch(std::exception &e)
	{
		std::cerr << "'inf': "<< e.what() << std::endl;
	}
}