/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 22:04:37 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/15 22:20:10 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string new_target ) :  AForm("RobotomyRequestForm", 72, 45) , target(new_target)
{
    std::cout << "RobotomyRequestForm default constructor called for target " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& src ) : AForm(src) , target(src.target)
{
	std::cout << "RobotomyRequestForm copy constructor for target " << target << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& )
{
	std::cout << "RobotomyRequestForm Copy assignment operator called for target " << target << std::endl;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "RobotomyRequestForm Destructor called for target " << target << std::endl;
}

std::string RobotomyRequestForm::getTarget( void ) const
{
    return (target);
}

void RobotomyRequestForm::safe_exec( void ) const
{
    static int robotomies = 0;
    
    std::cout << "RobotomyRequestForm is making some drilling noises Bzzz zzzzz " << std::endl;
    
    if (robotomies++ % 2 == 0)
        std::cout << target << " has been robotomized" << std::endl;
    else
        std::cout << target << " robotomy failed" << std::endl;
}