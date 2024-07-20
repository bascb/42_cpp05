/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:28:09 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/14 19:08:46 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm( std::string new_target );
        ShrubberyCreationForm( const ShrubberyCreationForm& );
        ShrubberyCreationForm& operator=( const ShrubberyCreationForm& );
        ~ShrubberyCreationForm( void );
        void safe_exec( void ) const;
        std::string getTarget( void ) const;
    private:
        const std::string target;
};

#endif