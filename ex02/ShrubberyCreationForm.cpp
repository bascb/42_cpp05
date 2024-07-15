/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:56:03 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/14 19:09:15 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string new_target ) :  AForm("ShrubberyCreationForm", 145, 137) , target(new_target)
{
    std::cout << "ShrubberyCreationForm default constructor called for target " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm(src) , target(src.target)
{
	std::cout << "ShrubberyCreationForm copy constructor for target " << target << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& )
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called for target " << target << std::endl;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "ShrubberyCreationForm Destructor called for target " << target << std::endl;
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
    return (target);
}

void ShrubberyCreationForm::safe_exec( void ) const
{
	std::ifstream	fin;
	
    std::cout << "ShrubberyCreationForm safe exec called for target " << target << std::endl;
	try
	{
		std::string f_name = "abbbcc.txt";
		fin.open(f_name.c_str(), std::ifstream::in);
		fin.close();
	}
	catch (std::exception & e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
