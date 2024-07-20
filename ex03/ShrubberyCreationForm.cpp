/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 10:56:03 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/20 18:57:20 by bcastelo         ###   ########.fr       */
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
	std::ofstream fout;

	std::string out_filename = target;
	out_filename += "_shrubbery";
	fout.open(out_filename.c_str(), std::ofstream::out);
	if (!fout.is_open())
	{
    	std::cerr << "Error opening file " << out_filename << std::endl;
    	return ;
    }
	fout << "" << std::endl;
	fout << "                  /\\                     " << std::endl;
	fout << "                 /  \\                    " << std::endl;
	fout << "                /    \\                   " << std::endl;
	fout << "               /      \\                  " << std::endl;
	fout << "              /        \\                 " << std::endl;
	fout << "             /          \\                " << std::endl;
	fout << "            /            \\               " << std::endl;
	fout << "           /______________\\              " << std::endl;
	fout << "                |TTT|                     " << std::endl;
	fout << "                |TTT|                     " << std::endl;
	fout << "                |TTT|                     " << std::endl;
	fout << "                |TTT|                     " << std::endl;
	fout << "##########################################" << std::endl;
	fout.close();
}
