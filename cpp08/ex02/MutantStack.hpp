#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <stack>
#include <deque>
#include <iterator>
template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type container_type;
		typedef typename container_type::iterator iterator;
		typedef typename container_type::const_iterator const_iterator;
		typedef typename container_type::reverse_iterator reverse_iterator;
		typedef typename container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator begin()
		{
			return this->c.begin();
		};
		
		iterator end()
		{
			return this->c.end();
		};
		
		const_iterator begin() const
		{
			return this->c.begin();
		};

		const_iterator end() const
		{
			return this->c.end();
		};

		reverse_iterator rbegin()
		{
			return this->c.rbegin();
		};

		reverse_iterator rend()
		{
			return this->c.rend();
		};

		const_reverse_iterator rbegin() const
		{
			return this->c.rebgin();

		};

		const_reverse_iterator rend() const
		{
			return this->c.rend();
		};
		
		MutantStack(): std::stack<T>()
		{

		};
		
		MutantStack(const MutantStack &cpy): std::stack<T>(cpy)
		{
			
		};
		
		MutantStack &operator=(const MutantStack &cpy)
		{
			std::stack<T>::operator=(cpy);	
			return *this;
		};
		
		~MutantStack()
		{};
};
#endif