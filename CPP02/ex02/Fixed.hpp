#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	private:
		int fixedPointNumber;
		static const int fractBits = 8;

	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int nb);
		Fixed(const float nb);
		
		// Destructor
		~Fixed();

		// Operators
		Fixed & operator=(const Fixed &assign);
		
		void	setRawBits( int const raw );
		int		getRawBits( void ) const;
		float	toFloat(void) const;
		int		toInt(void) const;


		// Arithmetic
		float	operator+(const Fixed& fixed);
		float	operator-(const Fixed& fixed);
		float	operator*(const Fixed& fixed);
		float	operator/(const Fixed& fixed);		
		// Comparison	
		bool	operator>(const Fixed& fixed);
		bool	operator<(const Fixed& fixed);
		bool	operator>=(const Fixed& fixed);
		bool	operator<=(const Fixed& fixed);
		bool	operator==(const Fixed& fixed);
		bool	operator!=(const Fixed& fixed);		
		// // Increment and Decrement
		// Fixed	operator++(void);
		// Fixed	operator++(int num);
		// Fixed	operator--(void);
		// Fixed	operator--(int num);		
		// Max and Min
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixedPointNumber);

#endif