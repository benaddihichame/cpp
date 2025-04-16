#include "Serializer.hpp"


Serializer::Serializer(){}
Serializer::~Serializer(){}
Serializer &Serializer::operator=(const Serializer &cpy)
{
	(void)cpy;
	return *this;
}
Serializer::Serializer(const Serializer &cpy)
{
	(void)cpy;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}
