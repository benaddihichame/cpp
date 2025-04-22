#include "Span.hpp"

Span::Span(unsigned int n): n(n){}
Span::Span(const Span &cpy): n(cpy.n){}
Span &Span::operator=(const Span &cpy)
{
	box = cpy.box;
	n = cpy.n;
	return *this;
}
Span::~Span(){}

void Span::addNumber(int number)
{
	if (box.size() >= n)
		throw SpanFullException();
	box.push_back(number);
}
unsigned int Span::shortestSpan()
{
	if (box.size() <= 1)
		throw NoSpanException();
	std::vector<int> sorted(box);
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for(size_t i = 1; i < sorted.size(); i++)
	{
		unsigned int currentSpan = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	return minSpan;
}
unsigned int Span::longestSpan()
{
	if (box.size() <= 1)
		throw NoSpanException();
	
	std::vector<int>::const_iterator min = std::min_element(this->box.begin(), this->box.end());
	std::vector<int>::const_iterator max = std::max_element(this->box.begin(), this->box.end());

	return static_cast<unsigned int>(*max - *min);
}
