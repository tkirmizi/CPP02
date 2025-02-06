/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkirmizi <tkirmizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:56:52 by tkirmizi          #+#    #+#             */
/*   Updated: 2025/02/06 17:48:47 by tkirmizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

/*
orthodox canonical class
1. default const
2. copy cost
3. copy assing opr
4. dest
*/

// 128  64   32   16    8    4    2    1

class Fixed{
	private:
		int _nbr;
		static const int _frbits = 8;
	public:
		Fixed(); // def constr
		Fixed(const Fixed& other); // copy constr
		Fixed& operator=(const Fixed& other); // copy assgn opr
		~Fixed(); // destructor
		int getRawbits(void) const;
		void setRawbits(int const raw);

};
Fixed::Fixed(): _nbr(0){
	std::cout << "Default constructor called" << std::endl;}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator caled" << std::endl;
	if (this != &other)
		_nbr = other._nbr;
	return *this;
}

int Fixed::getRawbits(void) const
{
	std::cout << "getRawbits member function called" << std::endl;
	return _nbr;
}

void Fixed::setRawbits(int const raw)
{
	_nbr = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int main(){
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawbits() << std::endl;
	std::cout << b.getRawbits() << std::endl;
	std::cout << c.getRawbits() << std::endl;
}
