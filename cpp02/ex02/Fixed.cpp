#include "Fixed.hpp"

/// CONSTRUCTOR AND DESTRUCTOR
Fixed::Fixed() : nb(0)
{
}
Fixed::~Fixed()
{
}
Fixed::Fixed(const int para)
{
	this->nb = para << Fixed::bit;
}

Fixed::Fixed(const float para)
{
	this->nb = roundf(para * (1 << this->bit)); 
}
Fixed::Fixed(const Fixed& other) : nb(other.nb)
{
}
//////////////////////////////////////////////////////////////////////////////////////
// =
Fixed	&Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->nb = other.getRawBits();
	return *this;
}


//////////////////////////////////////////////////////////////////////////////////////
// CONVERTION
float	Fixed::toFloat( void ) const 
{
	return (float)this->nb / (float)(1 << this->bit);
}

int	Fixed::toInt( void ) const
{
	return roundf(this->nb / (1 << this->bit));
}

//////////////////////////////////////////////////////////////////////////////////////
// SETTER ET GETTER
int Fixed::getRawBits( void ) const
{
	return (this->nb);
}

void Fixed::setRawBits( int const raw )
{
	this->nb = raw;
}


///////////////////////////////////////////////////////////////////////////////////////////
// COMPARAISON

bool	Fixed::operator>(const Fixed& other) const
{
	return this->nb > other.nb;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->nb < other.nb;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->nb != other.nb;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->nb == other.nb;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->nb >= other.nb;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->nb <= other.nb;
}

// CALCULE

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed res;

	res.setRawBits(this->nb + other.nb);
	return res;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed res;

	res.setRawBits(this->nb - other.nb);
	return res;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed res;

	res.setRawBits((this->nb * other.nb) >> this->bit);
	return res;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed res;

	res.setRawBits((this->nb << this->bit) / other.nb);
	return res;
}


// INCR DECR

Fixed& Fixed::operator++()
{
	this->nb++;
	return *this;
}
Fixed& Fixed::operator--()
{
	this->nb--;
	return *this;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->nb++;
	return tmp;
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->nb--;
	return tmp;
}

// MIN MAX
const Fixed&	Fixed::min(Fixed const &a, Fixed const &b) 
{ 
	return a < b ? a : b;
}

Fixed&		Fixed::min(Fixed &a, Fixed &b) 
{ 
	return a < b ? a : b;
}

const Fixed&	Fixed::max(Fixed const &a, Fixed const &b) 
{ 
	return a > b ? a : b;
}

Fixed&		Fixed::max(Fixed &a, Fixed &b) 
{ 
	return a > b ? a : b;
}

///////////////////////////////////////////////////////////////////////////////////////////
std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}