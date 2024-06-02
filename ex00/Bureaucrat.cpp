/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:45:50 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/02 18:36:04 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string new_name, int new_grade ) : name(new_name)
{
	std::cout << "Bureaucrat default constructor" << std::endl;
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
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

std::string Bureaucrat::getName( void ) const
{
    return (name);
}

int Bureaucrat::getGrade( void ) const
{
    return (grade);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &item)
{
	os << item.getName() << ", bureaucrat grade " << item.getGrade();
	return (os);
}