#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
	this->fixedPointNumber = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	this->fixedPointNumber = copy.getRawBits();
}

Fixed::Fixed(const int nb)
{
	std::cout << "\e[0;33mInt Constructor called of Fixed\e[0m" << std::endl;
	this->fixedPointNumber = nb << fractBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "\e[0;33mFloat Constructor called of Fixed\e[0m" << std::endl;
	this->fixedPointNumber = roundf(nb * (1 << fractBits));
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator= (const Fixed &assign)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &assign)
		this->fixedPointNumber = assign.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
}

int	Fixed::getRawBits(void) const
{
	return this->fixedPointNumber;
}

int Fixed::toInt( void ) const
{
	return this->fixedPointNumber >> fractBits;
}

float Fixed::toFloat(void) const
{
    return (float)this->fixedPointNumber / (1 << fractBits);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixedPointNumber)
{
	stream << fixedPointNumber.toFloat();
	return stream;
}
