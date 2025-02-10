/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <taha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:12:13 by taha              #+#    #+#             */
/*   Updated: 2025/02/07 10:15:08 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>


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

#endif