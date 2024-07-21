/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:03:06 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/21 17:20:14 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern( void );
        Intern( const Intern& );
        Intern& operator=( const Intern& );
        ~Intern( void );
        AForm* makeForm( std::string name, std::string target );
        typedef AForm* (Intern::*func_ptr) ( std::string target );
        class FormNotRecognizedException : public std::exception
        {
            public:
                const char *what(void) const throw();
        };
    private:
        AForm* newShrubberyForm( std::string target );
        AForm* newRobotomyForm( std::string target );
        AForm* newPresidentialForm( std::string target );
};

#endif