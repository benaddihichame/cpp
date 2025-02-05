#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
	std::string idea[100];
	public:
	Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& cpy);
	~Brain();

	void AppendIdea(std::string &idea, unsigned int num);
	void ShowIdea(void);
};
#endif