/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:05:48 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/16 22:34:36 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define WIDTH 60

void	print_border( void );

void	print_left(int space);

void	print_rigth(int space);

int	calculate_space(int header_len);

int	calculate_right_space(int header_len);

void	print_header(std::string header);

int	main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string test = argv[i];
		if (test == "h" || test == "help")
		{
			print_header("Options and usage");
			std::cout << "Options:" << std::endl;
			std::cout << std::endl;
			std::cout << "const - Test Constructors and print" << std::endl;
			std::cout << "h_exec_const - Test Constructor TooHigh Execute grade Exception" << std::endl;
			std::cout << "l_exec_const - Test Constructor TooLow Execute grade Exception" << std::endl;
			std::cout << "h_sign_const - Test Constructor TooHigh Sign grade Exception" << std::endl;
			std::cout << "l_sign_const - Test Constructor TooLow Sign grade Exception" << std::endl;
			std::cout << "form_signed - Test Sucecssfull form beSigned function" << std::endl;
			std::cout << "form_not_signed - Test Unsucecssfull form beSigned function" << std::endl;
			std::cout << std::endl;
			std::cout << "Usage example:" << std::endl;
			std::cout << std::endl;
			std::cout << argv[0] << " const" << std::endl;
			std::cout << std::endl;
			return (0);
		}
		else if (test == "const")
		{
			print_header("Testing constructor and object print");
			Form first("Original", 120, 80);
			Form second(first);
			Form third("Other", 50, 30);

			std::cout << "First: " << first << std::endl;
			std::cout << "Second: " << second << std::endl;
			std::cout << "Third: " << third << std::endl;

			third = first;
			std::cout << "Third: " << third << std::endl;
		}
		else if (test == "h_exec_const")
		{
			print_header("Testing Constructor TooHigh Execute grade Exception");
			try
			{
				std::cout << "Trying to create a Form with execute grade of 120" << std::endl;
				Form first("Correct", 120, 120);
				std::cout << "Trying to create a Form with execue grade of 0" << std::endl;
				Form second("Too High", 120, 0);
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "l_exec_const")
		{
			print_header("Testing Constructor TooLow Execute grade Exception");
			try
			{
				std::cout << "Trying to create a Form with execute grade of 120" << std::endl;
				Form first("Correct", 120, 120);
				std::cout << "Trying to create a Bureaucrat with execute grade of 151" << std::endl;
				Form second("Too Low", 120, 151);
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "h_sign_const")
		{
			print_header("Testing Constructor TooHigh Sign grade Exception");
			try
			{
				std::cout << "Trying to create a Form with sign grade of 120" << std::endl;
				Form first("Correct", 120, 120);
				std::cout << "Trying to create a Form with sign grade of 0" << std::endl;
				Form second("Too High", 0, 120);
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "l_sign_const")
		{
			print_header("Testing Constructor TooLow Sign grade Exception");
			try
			{
				std::cout << "Trying to create a Form with sign grade of 120" << std::endl;
				Form first("Correct", 120, 120);
				std::cout << "Trying to create a Bureaucrat with sign grade of 151" << std::endl;
				Form second("Too Low", 151, 120);
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "form_signed")
		{
			print_header("Testing Sucessfull form beSigned function");
			try
			{
				Form correct("Form with grade to sign = 80", 80, 120);
				Bureaucrat student("My grade is 79", 79);
				std::cout << student << std::endl;
				std::cout << correct << std::endl;
				std::cout << "Trying to sign form" << std::endl;
				correct.beSigned(student);
				std::cout << correct << std::endl;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "form_not_signed")
		{
			print_header("Testing Unsucessfull form beSigned function");
			try
			{
				Form correct("Form with grade to sign = 80", 80, 120);
				Bureaucrat student("My grade is 81", 81);
				std::cout << student << std::endl;
				std::cout << correct << std::endl;
				std::cout << "Trying to sign form" << std::endl;
				correct.beSigned(student);
				std::cout << correct << std::endl;
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
	}
	if (argc == 1)
	{
		print_header("Options and usage");
		std::cout << "Options:" << std::endl;
		std::cout << std::endl;
		std::cout << "const - Test Constructors and print" << std::endl;
		std::cout << "h_exec_const - Test Constructor TooHigh Execute grade Exception" << std::endl;
		std::cout << "l_exec_const - Test Constructor TooLow Execute grade Exception" << std::endl;
		std::cout << "h_sign_const - Test Constructor TooHigh Sign grade Exception" << std::endl;
		std::cout << "l_sign_const - Test Constructor TooLow Sign grade Exception" << std::endl;
		std::cout << "form_signed - Test Sucecssfull form beSigned function" << std::endl;
		std::cout << "form_not_signed - Test Unsucecssfull form beSigned function" << std::endl;
		std::cout << std::endl;
		std::cout << "Usage example:" << std::endl;
		std::cout << std::endl;
		std::cout << argv[0] << " const" << std::endl;
		std::cout << std::endl;
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