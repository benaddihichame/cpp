#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	
	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& cpy);
		void AppendIdea(const std::string &idea, unsigned int num);
		void ShowIdea(void);
		~Brain();
	};
#endif