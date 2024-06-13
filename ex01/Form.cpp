/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:55:15 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/13 21:46:54 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string new_name, int new_gradeToSign, int new_gradeToExecute ) : name(new_name) , isSigned(false) , gradeToSign(new_gradeToSign) , gradeToExecute(new_gradeToExecute)
{
	std::cout << "Form default constructor called for " << name << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form( const Form& src ) : name(src.name) , isSigned(src.isSigned) , gradeToSign(src.gradeToSign) , gradeToExecute(src.gradeToExecute)
{
	std::cout << "Form copy constructor" << std::endl;
}

Form& Form::operator=( const Form& src )
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->isSigned = src.isSigned;
	}
	return (*this);
}

Form::~Form( void )
{
	std::cout << "Form Destructor called for " << name << std::endl;
}

std::string Form::getName( void ) const
{
    return (name);
}

bool Form::getSigned( void ) const
{
	return (isSigned);
}

int Form::getGradeToSign( void ) const
{
    return (gradeToSign);
}

int Form::getGradeToExecute( void ) const
{
    return (gradeToExecute);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &item)
{
	os << item.getName() << ", Form is signed?  " << item.getSigned() << ", Grade to sign: " << item.getGradeToSign() << ", Grade to execute: " << item.getGradeToExecute();
	return (os);
}