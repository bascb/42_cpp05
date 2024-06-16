/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:50:11 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/16 22:16:04 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form( std::string new_name, int new_gradeToSign, int new_gradeToExecute );
        Form( const Form& );
		Form& operator=( const Form& );
		~Form( void );
        std::string getName( void ) const;
        bool getSigned( void ) const;
        int getGradeToSign( void ) const;
        int getGradeToExecute( void ) const;
        void beSigned( const Bureaucrat& );
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
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &item);

#endif