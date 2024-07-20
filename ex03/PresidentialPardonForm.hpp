/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:29:35 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/20 12:32:45 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm( std::string new_target );
        PresidentialPardonForm( const PresidentialPardonForm& );
        PresidentialPardonForm& operator=( const PresidentialPardonForm& );
        ~PresidentialPardonForm( void );
        void safe_exec( void ) const;
        std::string getTarget( void ) const;
    private:
        const std::string target;
};

#endif  