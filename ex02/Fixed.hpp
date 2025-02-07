/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:13 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 13:21:11 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>


class Fixed{
	private:
		int _nbr;
		static const int _frbits = 8;
	public:
		Fixed(); // def constr
		Fixed(const int n);
		Fixed (const float n);
		Fixed(const Fixed& other); // copy constr
		Fixed& operator=(const Fixed& other); // copy assgn opr
		~Fixed(); // destructor
		int getRawbits(void) const;
		void setRawbits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

		// Arithmetic operators
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;

		// Increment & Decrement
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		//Comparision operators
		bool operator>(const Fixed &other) const;
		bool operator<(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;
		
		//Min max functions
		// Static min-max functions
		static Fixed& min(Fixed& x, Fixed& y);
		static const Fixed& min(const Fixed& x, const Fixed& y);
		static Fixed& max(Fixed& x, Fixed& y);
		static const Fixed& max(const Fixed& x, const Fixed& y);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedObj);
#endif

