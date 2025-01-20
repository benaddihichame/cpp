#ifndef FIXED_H

# define FIXED_H
# include <iostream>

class Fixed
{
private:
	int num_comma;
	static const int bit;
public:
	Fixed();
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif