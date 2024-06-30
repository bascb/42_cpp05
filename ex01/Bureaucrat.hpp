/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:39:40 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/30 18:43:27 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
        Bureaucrat( std::string new_name, int new_grade );
        Bureaucrat( const Bureaucrat& );
		Bureaucrat& operator=( const Bureaucrat& );
		~Bureaucrat( void );
        std::string getName( void ) const;
        int getGrade( void ) const;
        void incGrade( void );
        void decGrade( void );
        void signForm( Form& );
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

std::ostream &operator<<(std::ostream &os, const Bureaucrat &item);

#endif