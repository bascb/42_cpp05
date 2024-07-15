/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:55:15 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/15 09:12:37 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( std::string new_name, int new_gradeToSign, int new_gradeToExecute ) : name(new_name) , isSigned(false) , gradeToSign(new_gradeToSign) , gradeToExecute(new_gradeToExecute)
{
	std::cout << "AForm default constructor called for " << name << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm( const AForm& src ) : name(src.name) , isSigned(src.isSigned) , gradeToSign(src.gradeToSign) , gradeToExecute(src.gradeToExecute)
{
	std::cout << "AForm copy constructor" << std::endl;
}

AForm& AForm::operator=( const AForm& src )
{
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->isSigned = src.isSigned;
	}
	return (*this);
}

AForm::~AForm( void )
{
	std::cout << "AForm Destructor called for " << name << std::endl;
}

std::string AForm::getName( void ) const
{
    return (name);
}

bool AForm::getSigned( void ) const
{
	return (isSigned);
}

int AForm::getGradeToSign( void ) const
{
    return (gradeToSign);
}

int AForm::getGradeToExecute( void ) const
{
    return (gradeToExecute);
}

void AForm::beSigned( const Bureaucrat& src)
{
	if (src.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	this->safe_exec();
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form is not signed!");
}

std::ostream &operator<<(std::ostream &os, const AForm &item)
{
	os << item.getName() << ", Form is signed? " << item.getSigned() << ", Grade to sign: " << item.getGradeToSign() << ", Grade to execute: " << item.getGradeToExecute();
	return (os);
}