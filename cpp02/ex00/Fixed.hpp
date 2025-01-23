#ifndef FIXED_H

# define FIXED_H
# include <iostream>

class Fixed
{
private:
	int value;
	static const int bit = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif