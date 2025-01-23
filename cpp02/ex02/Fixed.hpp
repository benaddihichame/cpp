#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>
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

		bool operator!=(const Fixed& other) const; 
		bool operator<=(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator<(const Fixed& other) const;
		bool operator==(const Fixed& other) const;

		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		static const Fixed&	min( Fixed const &a, Fixed const &b );
		static Fixed&		min( Fixed &a, Fixed &b );

		static const Fixed&	max( Fixed const &a, Fixed const &b );
		static Fixed&		max( Fixed &a, Fixed &b );

		~Fixed();

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};
std::ostream	&operator<<( std::ostream &op, Fixed const &f );

#endif