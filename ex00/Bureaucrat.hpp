/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:39:40 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/11 19:17:49 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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