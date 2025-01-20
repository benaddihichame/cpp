#include "Fixed.hpp"

Fixed::Fixed() : num_comma(0)
{
	std::cout << "Constructor was called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor was call\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function was called" << std::endl;
	return (this->num_comma);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function was called" << std::endl;

}