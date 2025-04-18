#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <string>
#include <iostream>

template<typename T>
class Array
{
	private:
		T *element;
		unsigned int sizeu;

	public:
		Array():element(NULL), sizeu(0)
		{

		}
		
		Array(unsigned int n): sizeu(n)
		{
			element = new T[n]();
		}
		
		Array(const Array &cpy): element(NULL), sizeu(0)
		{
			*this = cpy;
		}

		Array &operator=(const Array &cpy)
		{
			if (this != &cpy)
			{
				if (element)
					delete[] element;
				sizeu = cpy.sizeu;
				element = new T[sizeu]();
				for (unsigned int i= 0; i < sizeu; i++)
					element[i] = cpy.element[i];
			}
			return *this;
		}

		~Array()
		{
			if (element)
				delete[] element;			
		};

		unsigned int size()const
		{
			return sizeu;
		}

		T &operator[](unsigned int i)
		{
			if (i >= sizeu)
				throw std::exception();
			return element[i];
		}
};
#endif