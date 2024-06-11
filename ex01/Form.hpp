/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:50:11 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/11 19:53:42 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Form
{
    public:
        Form( std::string new_name, int new_grade );
        Form( const Form& );
		Form& operator=( const Form& );
		~Form( void );
        std::string getName( void ) const;
        int getGrade( void ) const;
        void incGrade( void );
        void decGrade( void );
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
    private:
        const std::string name;
        int grade;
};

std::ostream &operator<<(std::ostream &os, const Form &item);

#endif