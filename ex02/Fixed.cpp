/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:21 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 15:48:53 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed(): _nbr(0){}
Fixed::Fixed(const int n): _nbr(n << _frbits){}
Fixed::Fixed (const float n): _nbr(std::roundf (n * (1 << _frbits))){}

// Copy constructor
Fixed::Fixed(const Fixed& other){*this = other;}

// Copy assgn operator
Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		this->_nbr = other._nbr;
	return *this;
}

// Destructor
Fixed::~Fixed(){}

// Increment & Decrement
Fixed& Fixed::operator++() {this->_nbr += 1; return *this;}
Fixed Fixed::operator++(int) { Fixed old = *this; this->_nbr += 1; return old;}
Fixed& Fixed::operator--() {this->_nbr -= 1; return *this;}
Fixed Fixed::operator--(int) { Fixed old = *this; this->_nbr -= 1; return old;}

//Comparision operators
bool Fixed::operator>(const Fixed &other) const {return this->_nbr > other._nbr;}
bool Fixed::operator<(const Fixed &other) const {return other > *this;}
bool Fixed::operator>=(const Fixed &other) const {return !(*this < other);}
bool Fixed::operator<=(const Fixed &other) const {return !(*this > other);}
bool Fixed::operator==(const Fixed &other) const {return this->_nbr == other._nbr;}
bool Fixed::operator!=(const Fixed &other) const {return !(*this == other);}

// Min max functions
Fixed& Fixed::min(Fixed& x, Fixed& y) {return (x.getRawbits() <= y.getRawbits() ? x : y);}
Fixed& Fixed::max(Fixed& x, Fixed& y) {return (x.getRawbits() >= y.getRawbits() ? x : y);}
const Fixed& Fixed::min(const Fixed& x, const Fixed& y) {return (x.getRawbits() <= y.getRawbits() ? x : y);}
const Fixed& Fixed::max(const Fixed& x, const Fixed& y) {return (x.getRawbits() >= y.getRawbits() ? x : y);}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &other) const{
	Fixed temp;
	temp._nbr = _nbr + other._nbr;
	return temp;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed temp;
	temp._nbr = _nbr - other._nbr;
	return temp;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed temp;
	 temp._nbr = (_nbr * other._nbr) >> _frbits;
	return temp;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed temp;
	 temp._nbr = (_nbr << _frbits) / other._nbr;
	return temp;
}

// Member functions
int Fixed::getRawbits(void) const{return _nbr;}
void Fixed::setRawbits(int const raw){_nbr = raw;}
int Fixed::toInt( void ) const {return _nbr >> _frbits;}
float Fixed::toFloat( void ) const {return (float)_nbr / 256;}
std::ostream& operator<<(std::ostream& os, const Fixed& fixedObj){os << fixedObj.toFloat();return os;}
