/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:13 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 11:55:04 by taha             ###   ########.fr       */
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
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedObj);
#endif