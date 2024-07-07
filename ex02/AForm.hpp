/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:50:11 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/07 19:07:12 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm( std::string new_name, int new_gradeToSign, int new_gradeToExecute );
        AForm( const AForm& );
		AForm& operator=( const AForm& );
		virtual ~AForm( void );
        std::string getName( void ) const;
        bool getSigned( void ) const;
        int getGradeToSign( void ) const;
        int getGradeToExecute( void ) const;
        void beSigned( const Bureaucrat& );
        void execute(Bureaucrat const & executor) const;
        virtual void safe_exec( void ) const = 0;
        virtual std::string getTarget( void ) const = 0;
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

std::ostream &operator<<(std::ostream &os, const AForm &item);

#endif