/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:05:48 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/21 17:06:02 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define WIDTH 60

void	print_border( void );

void	print_left(int space);

void	print_rigth(int space);

int	calculate_space(int header_len);

int	calculate_right_space(int header_len);

void	print_header(std::string header);

void	print_comment(std::string comment);

void	print_help(char *prog_name);

int	main(int argc, char **argv)
{
	std::string test;
	
	for (int i = 1; i < argc; i++)
	{
		test = argv[i];
		if (test == "h" || test == "help")
		{
			print_help(argv[0]);
			return (0);
		}
		if (test == "int_const" || test == "all" || test == "int*")
		{
			print_header("Testing Intern class constructors");
			try
			{
				print_comment("Construct objects");
				Intern Original;
				Intern Copy(Original);
				Intern Assigned;
				Intern* Ptr = new Intern;
				
				Assigned = Copy;
				print_comment("Destruct objects");
				delete Ptr;
				
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "int_make" || test == "all" || test == "int*")
		{
			AForm *s_form = NULL;
			AForm *r_form = NULL;
			AForm *p_form = NULL;
			print_header("Testing Intern class make forms with success");
			try
			{
				print_comment("Construct objects");
				Intern worker;
				
				print_comment("Make forms");
				s_form = worker.makeForm("shrubbery creation", "garden");
				r_form = worker.makeForm("robotomy request", "home");
				p_form = worker.makeForm("presidential pardon", "street");

				print_comment("Prints forms data");
				std::cout << *s_form << std::endl;
				std::cout << *r_form << std::endl;
				std::cout << *p_form << std::endl;

				print_comment("Destruct objects");
				delete s_form;
				delete r_form;
				delete p_form;
			}
			catch (std::exception & e)
			{
				delete s_form;
				delete r_form;
				delete p_form;
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "int_make_error" || test == "all" || test == "int*")
		{
			AForm *s_form = NULL;
			AForm *r_form = NULL;
			AForm *p_form = NULL;
			AForm *e_form = NULL;
			print_header("Testing Intern class trying to make a form that does not exist");
			try
			{
				print_comment("Construct objects");
				Intern worker;
				
				print_comment("Make forms");
				s_form = worker.makeForm("shrubbery creation", "garden");
				r_form = worker.makeForm("robotomy request", "home");
				p_form = worker.makeForm("presidential pardon", "street");
				e_form = worker.makeForm("city tour", "street");

				print_comment("Prints forms data");
				std::cout << *s_form << std::endl;
				std::cout << *r_form << std::endl;
				std::cout << *p_form << std::endl;
				std::cout << *e_form << std::endl;

				print_comment("Destruct objects");
				delete s_form;
				delete r_form;
				delete p_form;
				delete e_form;
			}
			catch (std::exception & e)
			{
				delete s_form;
				delete r_form;
				delete p_form;
				delete e_form;
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
	if (argc == 1 || test == "all")
	{
		AForm *rrf = NULL;
		print_header("Subject example");
		try
		{
			print_comment("Construct objects");
			Intern someRandomIntern;
			
			print_comment("Make form");
			rrf = someRandomIntern.makeForm("robotomy request", "Bender");
			print_comment("Prints forms data");
			std::cout << *rrf << std::endl;
			
			print_comment("Destruct objects");
		}
		catch (std::exception & e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
		delete rrf;
	}
	return (0);
}

void	print_border( void )
{
	for (int i = 0; i < WIDTH; i++)
		std::cout << "*";
	std::cout << std::endl;
}

void	print_left(int space)
{
	std::cout << "*";
	for (int i = 0; i < space; i++)
		std::cout << " ";
}

void	print_rigth(int space)
{
	for (int i = 0; i < space; i++)
		std::cout << " ";
	std::cout << "*" << std::endl; 
}

int	calculate_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	return (space);
}

int	calculate_right_space(int header_len)
{
	int	space;

	space = (WIDTH - header_len - 2) / 2;
	space += (WIDTH - header_len - 2) % 2;
	return (space);
}

void	print_header(std::string header)
{
	int space;

	space = calculate_space(header.size());
	print_border();
	print_left(space);
	std::cout << header;
	space = calculate_right_space(header.size());
	print_rigth(space);
	print_border();
}

void	print_comment(std::string comment)
{
	int space;

	space = calculate_space(comment.size());
	std::cout << std::endl;
	print_left(space);
	std::cout << comment;
	space = calculate_right_space(comment.size());
	print_rigth(space);
	std::cout << std::endl;
}

void	print_help(char *prog_name)
{
	print_header("Options and usage");
	std::cout << "Options:" << std::endl;
	std::cout << std::endl;
	std::cout << "int_const - Testing Intern class constructors" << std::endl;
	std::cout << "int_make - Testing Intern class make forms with success" << std::endl;
	std::cout << "int_make_error - Testing Intern class trying to make a form that does not exists" << std::endl;
	std::cout << "all - Run all tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Usage example:" << std::endl;
	std::cout << std::endl;
	std::cout << prog_name << " shrub_const" << std::endl;
	std::cout << std::endl;
}