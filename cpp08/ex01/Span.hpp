#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>

class Span
{
	private:
	unsigned int n;
	std::vector<int> list;
	public:
	Span(unsigned int n);
	Span(const Span &cpy);
	Span &operator=(const Span &cpy);
	~Span();
	void addNumber(int number);
	
};
#endif