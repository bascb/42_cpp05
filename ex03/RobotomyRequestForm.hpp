/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:00:55 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/15 22:03:40 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm( std::string new_target );
        RobotomyRequestForm( const RobotomyRequestForm& );
        RobotomyRequestForm& operator=( const RobotomyRequestForm& );
        ~RobotomyRequestForm( void );
        void safe_exec( void ) const;
        std::string getTarget( void ) const;
    private:
        const std::string target;
};

#endif