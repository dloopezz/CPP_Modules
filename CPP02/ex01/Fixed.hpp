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
};

std::ostream& operator<<(std::ostream& stream, const Fixed& fixedPointNumber);

#endif