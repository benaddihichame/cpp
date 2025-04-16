#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <string>
#include <iostream>
#include <stdint.h>
#include <cstddef>

class Serializer
{
	private:
	Serializer();
	~Serializer();
	Serializer &operator=(const Serializer &cpy);
	Serializer(const Serializer &cpy);
	public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};
#endif