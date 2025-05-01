#include "RPN.hpp"


RPN::RPN(){}
RPN::RPN(const RPN &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(const RPN &cpy)
{
    if (this != &cpy)
    {
        this->theValue = cpy.theValue;
    }
    return *this;
}

RPN::~RPN(){}

bool	RPN::isOperator(char c)const
{
    if (c == '+' || c == '/' ||c == '*' ||c == '-')
        return true;
    else
        return false;
}


bool	RPN::isNumb(char c)const
{
    if (c >= '0' && c<= '9')
        return true;
    else 
        return false;
}

void	RPN::doOperation(char op)
{
    if (theValue.size() < 2)
        throw std::runtime_error("Error: not enough operands for operation");
    
    int b = theValue.top();
    theValue.pop();
    int a = theValue.top();
    theValue.pop();

    switch (op)
    {
    case '+':
        theValue.push(a + b);
        break;
    
    case '-':
        theValue.push(a - b);
        break;
    
    case '*':
        theValue.push(a * b);
        break;
    
    case '/':
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        theValue.push(a / b);
        break;
    
    default:
        throw std::runtime_error("Error: Uknow operator");
    }
}

int	RPN::doMath(const std::string &expression)
{
    while (!theValue.empty())
        theValue.pop();
    for (std::string::const_iterator it = expression.begin(); it != expression.end(); it++)
    {
        char c = *it;

        if (isNumb(c) == true)
        {
            theValue.push(c - '0');
        }
        else if (isOperator(c) == true)
        {
            doOperation(c);
        }
        else if (c == ' ')
        {
            continue;
        }
        else
        {
            throw std::runtime_error("Error: invalide character in expression");
        }
    }

    if (theValue.size() != 1)
        throw std::runtime_error("Error: invalid RPN expression (too many operands)");
    return theValue.top();
}