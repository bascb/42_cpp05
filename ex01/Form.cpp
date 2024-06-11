/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:55:15 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/11 19:56:09 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( std::string new_name, int new_grade ) : name(new_name)
{
	std::cout << "Form default constructor called for " << name << std::endl;
	if (new_grade < 1)
		throw Form::GradeTooHighException();
	if (new_grade > 150)
		throw Form::GradeTooLowException();
    grade = new_grade;
}

Form::Form( const Form& src ) : name(src.name) , grade(src.grade)
{
	std::cout << "Form copy constructor" << std::endl;
}

Form& Form::operator=( const Form& src )
{
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &src)
	{
        this->grade = src.grade;
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

int Form::getGrade( void ) const
{
    return (grade);
}

void  Form::incGrade( void )
{
	if (grade - 1 < 1)
		throw Form::GradeTooHighException();
	grade--;	
}

void  Form::decGrade( void )
{
	if (grade + 1 > 150)
		throw Form::GradeTooLowException();
	grade++;	
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
	os << item.getName() << ", Form grade " << item.getGrade();
	return (os);
}