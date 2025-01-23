#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private: 
		int nb;
		static const int bit = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& nb);

		Fixed& operator=(const Fixed& other);
		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream	&operator<<( std::ostream &op, Fixed const &f );


#endif