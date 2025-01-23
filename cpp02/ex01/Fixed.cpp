#include "Fixed.hpp"

Fixed::Fixed() : nb(0)
{
	std::cout << "Constructor was called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor was called" << std::endl;
}
Fixed::Fixed(const int para)
{
	std::cout << "INT Constructor called" << std::endl;
	this->nb = para << Fixed::bit;
}

Fixed::Fixed(const float para)
{
	std::cout << "FLOAT Constructor called" << std::endl;
	this->nb = roundf(para * (1 << this->bit)); 
}
Fixed::Fixed(const Fixed& other) : nb(other.nb)
{
	std::cout << "Copy constructor called" << std::endl;
}
Fixed	&Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->nb = other.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}

float	Fixed::toFloat( void ) const 
{
	return (float)this->nb / (float)(1 << this->bit);
}

int	Fixed::toInt( void ) const
{
	return roundf(this->nb / (1 << this->bit));
}

int Fixed::getRawBits( void ) const
{
	return (this->nb);
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function was called" << std::endl;
	this->nb = raw;
}
