/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:05:48 by bcastelo          #+#    #+#             */
/*   Updated: 2024/07/20 19:22:53 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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
	for (int i = 1; i < argc; i++)
	{
		std::string test = argv[i];
		if (test == "h" || test == "help")
		{
			print_help(argv[0]);
			return (0);
		}
		if (test == "shrub_const" || test == "all" || test == "shrub*")
		{
			print_header("Testing ShrubberyCreationForm concrete class constructors");
			try
			{
				print_comment("Construct objects");
				AForm* home = new ShrubberyCreationForm("home");
				AForm* garden = new ShrubberyCreationForm("garden");
				AForm* street = new ShrubberyCreationForm("street");
				ShrubberyCreationForm city("city");

				print_comment("Get data");
				std::cout << "Form of type " << home->getName() << " with target " << home->getTarget() << std::endl;
				std::cout << *home << std::endl;
				std::cout << "Form of type " << garden->getName() << " with target " << garden->getTarget() << std::endl;
				std::cout << *garden << std::endl;
				std::cout << "Form of type " << street->getName() << " with target " << street->getTarget() << std::endl;
				std::cout << *street << std::endl;
				std::cout << "Form of type " << city.getName() << " with target " << city.getTarget() << std::endl;
				std::cout << city << std::endl;

				print_comment("Destruct objects");
				delete home;
				delete garden;
				delete street;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "shrub_exec" || test == "all" || test == "shrub*")
		{
			print_header("Testing ShrubberyCreationForm concrete class execute");
			try
			{
				print_comment("Construct objects");
				AForm* home = new ShrubberyCreationForm("home");
				Bureaucrat correct("Grade 109", 109);
				ShrubberyCreationForm city("city");
				
				print_comment("Signed");
				home->beSigned(correct);
				city.beSigned(correct);
				print_comment("Execute");
				home->execute(correct);
				city.execute(correct);
			
				print_comment("Destruct objects");
				delete home;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "shrub_not_signed" || test == "all" || test == "shrub*")
		{
			AForm* home = NULL;
			print_header("Testing ShrubberyCreationForm concrete class execute wuthout being signed");
			try
			{
				print_comment("Construct objects");
				home = new ShrubberyCreationForm("home");
				Bureaucrat correct("Grade 109", 109);
				ShrubberyCreationForm city("city");
				
				print_comment("Execute");
				home->execute(correct);
				city.execute(correct);
			
				print_comment("Destruct objects");
				delete home;
			}
			catch (std::exception & e)
			{
				delete home;
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "shrub_w_grade" || test == "all" || test == "shrub*")
		{
			print_header("Testing ShrubberyCreationForm execute with wrong grade");
			try
			{
				print_comment("Construct objects");
				ShrubberyCreationForm home("home");
				Bureaucrat incorrect("Grade 144", 144);
				
				home.beSigned(incorrect);
				print_comment("Try to execute");
				home.execute(incorrect);
			
				print_comment("Destruct objects");
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "robot_const" || test == "all" || test == "robot*")
		{
			print_header("Testing RobotomyRequestForm concrete class constructors");
			try
			{
				print_comment("Construct objects");
				AForm* home = new RobotomyRequestForm("home");
				AForm* garden = new RobotomyRequestForm("garden");
				AForm* street = new RobotomyRequestForm("street");
				RobotomyRequestForm city("city");

				print_comment("Get data");
				std::cout << "Form of type " << home->getName() << " with target " << home->getTarget() << std::endl;
				std::cout << *home << std::endl;
				std::cout << "Form of type " << garden->getName() << " with target " << garden->getTarget() << std::endl;
				std::cout << *garden << std::endl;
				std::cout << "Form of type " << street->getName() << " with target " << street->getTarget() << std::endl;
				std::cout << *street << std::endl;
				std::cout << "Form of type " << city.getName() << " with target " << city.getTarget() << std::endl;
				std::cout << city << std::endl;

				print_comment("Destruct objects");
				delete home;
				delete garden;
				delete street;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "robot_exec" || test == "all" || test == "robot*")
		{
			print_header("Testing RobotomyRequestForm concrete class execute");
			try
			{
				print_comment("Construct objects");
				AForm* home = new RobotomyRequestForm("home");
				Bureaucrat correct("Grade 44", 44);
				RobotomyRequestForm city("city");
				
				print_comment("Signed");
				home->beSigned(correct);
				city.beSigned(correct);
				print_comment("Execute");
				home->execute(correct);
				city.execute(correct);
			
				print_comment("Destruct objects");
				delete home;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "robot_not_signed" || test == "all" || test == "robot*")
		{
			AForm* home = NULL;
			print_header("Testing RobotomyRequestForm concrete class execute wuthout being signed");
			try
			{
				print_comment("Construct objects");
				home = new RobotomyRequestForm("home");
				Bureaucrat correct("Grade 44", 44);
				RobotomyRequestForm city("city");
				
				print_comment("Execute");
				home->execute(correct);
				city.execute(correct);
			
				print_comment("Destruct objects");
				delete home;
			}
			catch (std::exception & e)
			{
				delete home;
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "robot_w_grade" || test == "all" || test == "robot*")
		{
			print_header("Testing RobotomyRequestForm execute with wrong grade");
			try
			{
				print_comment("Construct objects");
				RobotomyRequestForm home("home");
				Bureaucrat incorrect("Grade 71", 71);

				home.beSigned(incorrect);	
				print_comment("Try to execute");
				home.execute(incorrect);
			
				print_comment("Destruct objects");
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "pres_const" || test == "all" || test == "pres*")
		{
			print_header("Testing PresidentialPardonForm concrete class constructors");
			try
			{
				print_comment("Construct objects");
				AForm* home = new PresidentialPardonForm("home");
				AForm* garden = new PresidentialPardonForm("garden");
				AForm* street = new PresidentialPardonForm("street");
				PresidentialPardonForm city("city");

				print_comment("Get data");
				std::cout << "Form of type " << home->getName() << " with target " << home->getTarget() << std::endl;
				std::cout << *home << std::endl;
				std::cout << "Form of type " << garden->getName() << " with target " << garden->getTarget() << std::endl;
				std::cout << *garden << std::endl;
				std::cout << "Form of type " << street->getName() << " with target " << street->getTarget() << std::endl;
				std::cout << *street << std::endl;
				std::cout << "Form of type " << city.getName() << " with target " << city.getTarget() << std::endl;
				std::cout << city << std::endl;

				print_comment("Destruct objects");
				delete home;
				delete garden;
				delete street;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "pres_exec" || test == "all" || test == "pres*")
		{
			print_header("Testing PresidentialPardonForm concrete class execute");
			try
			{
				print_comment("Construct objects");
				AForm* home = new PresidentialPardonForm("home");
				Bureaucrat correct("Grade 4", 4);
				PresidentialPardonForm city("city");
				
				print_comment("Signed");
				home->beSigned(correct);
				city.beSigned(correct);
				print_comment("Execute");
				home->execute(correct);
				city.execute(correct);
			
				print_comment("Destruct objects");
				delete home;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "pres_not_signed" || test == "all" || test == "pres*")
		{
			AForm* home = NULL;
			print_header("Testing PresidentialPardonForm concrete class execute wuthout being signed");
			try
			{
				print_comment("Construct objects");
				home = new PresidentialPardonForm("home");
				Bureaucrat correct("Grade 4", 4);
				PresidentialPardonForm city("city");
				
				print_comment("Execute");
				home->execute(correct);
				city.execute(correct);
			
				print_comment("Destruct objects");
				delete home;
			}
			catch (std::exception & e)
			{
				delete home;
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "pres_w_grade" || test == "all" || test == "pres*")
		{
			print_header("Testing PresidentialPardonForm execute with wrong grade");
			try
			{
				print_comment("Construct objects");
				PresidentialPardonForm home("home");
				Bureaucrat incorrect("Grade 6", 6);

				home.beSigned(incorrect);	
				print_comment("Try to execute");
				home.execute(incorrect);
			
				print_comment("Destruct objects");
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		if (test == "exec_form" || test == "all")
		{
			print_header("Testing Bureaucrat executeForm member function");
			try
			{
				print_comment("Construct objects");
				PresidentialPardonForm home("home");
				RobotomyRequestForm garden("garden");
				ShrubberyCreationForm street("street");
				Bureaucrat very_low("Grade 147", 147);
				Bureaucrat low("Grade 120", 120);
				Bureaucrat medium("Grade 44", 44);
				Bureaucrat high("Grade 22", 22);
				Bureaucrat very_high("Grade 5", 5);

				print_comment("Prints forms minimal grades");
				std::cout << home << std::endl;
				std::cout << garden << std::endl;
				std::cout << street << std::endl;

				print_comment("Bureaucrat with grade 147 tries to sign and execute all forms");
				very_low.signForm(street);
				very_low.executeForm(street);
				very_low.signForm(garden);
				very_low.executeForm(garden);
				very_low.signForm(home);
				very_low.executeForm(home);
				
				print_comment("Bureaucrat with grade 120 tries to sign and execute all forms");
				low.signForm(street);
				low.executeForm(street);
				low.signForm(garden);
				low.executeForm(garden);
				low.signForm(home);
				low.executeForm(home);

				print_comment("Bureaucrat with grade 44 tries to sign and execute all forms");
				medium.signForm(street);
				medium.executeForm(street);
				medium.signForm(garden);
				medium.executeForm(garden);
				medium.signForm(home);
				medium.executeForm(home);

				print_comment("Bureaucrat with grade 22 tries to sign and execute all forms");
				high.signForm(street);
				high.executeForm(street);
				high.signForm(garden);
				high.executeForm(garden);
				high.signForm(home);
				high.executeForm(home);

				print_comment("Bureaucrat with grade 5 tries to sign and execute all forms");
				very_high.signForm(street);
				very_high.executeForm(street);
				very_high.signForm(garden);
				very_high.executeForm(garden);
				very_high.signForm(home);
				very_high.executeForm(home);
				
				print_comment("Destruct objects");
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
	if (argc == 1)
	{
		print_help(argv[0]);
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
	std::cout << "shrub_const - Testing ShrubberyCreationForm concrete class constructors" << std::endl;
	std::cout << "shrub_exec - Testing ShrubberyCreationForm concrete class execute" << std::endl;
	std::cout << "shrub_not_signed - Testing ShrubberyCreationForm concrete class execute wuthout being signed" << std::endl;
	std::cout << "shrub_w_grade - Testing ShrubberyCreationForm concrete class execute" << std::endl;
	std::cout << "robot_const - Testing RobotomyRequestForm concrete class constructors" << std::endl;
	std::cout << "robot_exec - Testing RobotomyRequestForm concrete class execute" << std::endl;
	std::cout << "robot_not_signed - Testing RobotomyRequestForm concrete class execute wuthout being signed" << std::endl;
	std::cout << "robot_w_grade - Testing RobotomyRequestForm concrete class execute" << std::endl;
	std::cout << "pres_const - Testing PresidentialPardonForm concrete class constructors" << std::endl;
	std::cout << "pres_exec - Testing PresidentialPardonForm concrete class execute" << std::endl;
	std::cout << "pres_not_signed - Testing PresidentialPardonForm concrete class execute wuthout being signed" << std::endl;
	std::cout << "pres_w_grade - Testing PresidentialPardonForm concrete class execute" << std::endl;
	std::cout << "exec_form - Testing Bureaucrat executeForm member function" << std::endl;
	std::cout << "all - Run all tests" << std::endl;
	std::cout << std::endl;
	std::cout << "Usage example:" << std::endl;
	std::cout << std::endl;
	std::cout << prog_name << " shrub_const" << std::endl;
	std::cout << std::endl;
}