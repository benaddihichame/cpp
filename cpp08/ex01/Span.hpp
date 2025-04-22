#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
	private:
	unsigned int n;
	std::vector<int> box;
	
	public:
	Span(unsigned int n);
	Span(const Span &cpy);
	Span &operator=(const Span &cpy);
	~Span();

	void addNumber(int number);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	template <typename IT>
	void	addRange(IT begin, IT end)
	{
		while (begin != end)
		{
				if (box.size() >= n)
					throw SpanFullException();
				box.push_back(*begin);
				++begin;
		}
	}

	class SpanFullException : public std::exception{
		public:
			virtual const char* what() const throw() {
				return "Span is full. cannot add more numbers";
			}
	};
	
	class NoSpanException : public std::exception{
		public:
			virtual const char* what() const throw() {
				return "Cannot find any span with less than 2 elements";
			}
	};
	
};
#endif