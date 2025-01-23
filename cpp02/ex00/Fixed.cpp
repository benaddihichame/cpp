#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Constructor was called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed	&Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->value = other.getRawBits();
	return *this;
}
Fixed::~Fixed()
{
	std::cout << "Destructor was call\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function was called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function was called" << std::endl;
	this->value = raw;
}