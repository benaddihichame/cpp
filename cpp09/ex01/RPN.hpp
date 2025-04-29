#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <math.h>
#include <string>
class RPN
{
	private:
	std::stack<int> stack;
	public:
	RPN();
	RPN(const RPN &cpy);
	RPN &operator=(const RPN &cpy);
	~RPN();
};

#endif