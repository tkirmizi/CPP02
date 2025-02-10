/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:21 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 10:23:04 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _nbr(0){
	std::cout << "Default constructor called" << std::endl;} // def constructor

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl; // copy constructor
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl; // copy assgn operator
	if (this != &other)
		this->_nbr = other._nbr;
	return *this;
}

Fixed::~Fixed(){ // destructor
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawbits(void) const{
	std::cout << "getRawbits member function called" << std::endl;
	return _nbr;
}

void Fixed::setRawbits(int const raw){
	_nbr = raw;
}
