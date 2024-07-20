/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 12:33:26 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/20 13:14:09 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string new_target ) :  AForm("PresidentialPardonForm", 25, 5) , target(new_target)
{
	std::cout << "PresidentialPardonForm default constructor called for target " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& src ) : AForm(src) , target(src.target)
{
	std::cout << "PresidentialPardonForm copy constructor for target " << target << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& )
{
	std::cout << "PresidentialPardonForm Copy assignment operator called for target " << target << std::endl;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "PresidentialPardonForm Destructor called for target " << target << std::endl;
}

std::string PresidentialPardonForm::getTarget( void ) const
{
	return (target);
}

void PresidentialPardonForm::safe_exec( void ) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}