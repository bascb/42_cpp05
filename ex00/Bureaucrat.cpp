/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:45:50 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/10 19:43:01 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string new_name, int new_grade ) : name(new_name)
{
	std::cout << "Bureaucrat default constructor called for " << name << std::endl;
	if (new_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (new_grade > 150)
		throw Bureaucrat::GradeTooLowException();
    grade = new_grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& src ) : name(src.name) , grade(src.grade)
{
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& src )
{
	std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
	if (this != &src)
	{
        this->grade = src.grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat Destructor called for " << name << std::endl;
}

std::string Bureaucrat::getName( void ) const
{
    return (name);
}

int Bureaucrat::getGrade( void ) const
{
    return (grade);
}

void  Bureaucrat::incGrade( void )
{
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;	
}

void  Bureaucrat::decGrade( void )
{
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;	
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &item)
{
	os << item.getName() << ", bureaucrat grade " << item.getGrade();
	return (os);
}