/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:31:55 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/21 17:22:54 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
    std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern( const Intern& )
{
    std::cout << "Intern default copy constructor" << std::endl;
}

Intern& Intern::operator=( const Intern& )
{
    std::cout << "Intern default copy assignment operator" << std::endl;
    return (*this);
}

Intern::~Intern( void )
{
    std::cout << "Intern default destructor" << std::endl;
}

AForm* Intern::newShrubberyForm( std::string target )
{
    return (new ShrubberyCreationForm(target));
}

AForm* Intern::newRobotomyForm( std::string target )
{
    return (new RobotomyRequestForm(target));
}

AForm* Intern::newPresidentialForm( std::string target )
{
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm( std::string name, std::string target )
{
    func_ptr functions[] = {&Intern::newShrubberyForm, &Intern::newRobotomyForm, &Intern::newPresidentialForm};
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    std::string	forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int	i = 0;

	while (i < 3 && names[i].compare(name))
        i++;
    if (i < 3)
    {
        std::cout << "Intern creates " << forms[i] << std::endl;
        return ((this->*functions[i])(target));
    }
    throw Intern::FormNotRecognizedException();
    return (NULL);
}

const char *Intern::FormNotRecognizedException::what(void) const throw()
{
	return ("Form not recognized!");
}