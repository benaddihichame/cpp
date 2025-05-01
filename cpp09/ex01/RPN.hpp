#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <math.h>
#include <string>
class RPN
{
	private:
		std::stack<int> theValue;
		bool	isOperator(char c)const;
		bool	isNumb(char c)const;
	public:
		RPN();
		RPN(const RPN &cpy);
		RPN &operator=(const RPN &cpy);
		~RPN();
		void	doOperation(char op);
		int	doMath(const std::string &e);
};

#endif