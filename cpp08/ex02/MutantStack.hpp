#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>
#include <deque>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{

		};
		
		MutantStack(const MutantStack &cpy)
		{
			
		};
		
		MutantStack &operator=(const MutantStack &cpy)
		{

		};
		
		~MutantStack()
		{

		};

};
#endif