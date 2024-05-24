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


// Arithmetic

float Fixed::operator+(const Fixed &fixed)
{
	return this->toFloat() + fixed.toFloat();
}

float Fixed::operator-(const Fixed &fixed)
{
	return this->toFloat() - fixed.toFloat();
}

float Fixed::operator*(const Fixed &fixed)
{
	return this->toFloat() * fixed.toFloat();
}

float Fixed::operator/(const Fixed &fixed)
{
	return this->toFloat() / fixed.toFloat();
}

// Comparison

bool Fixed::operator>(const Fixed &fixed)
{
	if (this->toFloat() > fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &fixed)
{
	if (this->toFloat() < fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed &fixed)
{
	if (this->toFloat() >= fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed &fixed)
{
	if (this->toFloat() <= fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed &fixed)
{
	if (this->toFloat() == fixed.toFloat())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed &fixed)
{
	if (this->toFloat() != fixed.toFloat())
		return true;
	return false;
}

// Increment and Decrement

Fixed	Fixed::operator++(void)
{
	this->fixedPointNumber++;
	return *this;
}

Fixed	Fixed::operator--(void)
{
	fixedPointNumber--;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;

	this->fixedPointNumber++;
	return temp;
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;

	fixedPointNumber--;
	return temp;
}


// Max and Min
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return b;
	return a;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return b;
	return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return b;
	return a;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return b;
	return a;
}
