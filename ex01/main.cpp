/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:05:48 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/13 20:12:45 by bcastelo         ###   ########.fr       */
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
			std::cout << "h_const - Test Constructor TooHigh Exception" << std::endl;
			std::cout << "l_const - Test Constructor TooLow Exception" << std::endl;
			std::cout << "i_grade - Test Grade incrementor" << std::endl;
			std::cout << "d_grade - Test Grade decrementor" << std::endl;
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
		else if (test == "h_const")
		{
			print_header("Testing Constructor TooHigh Exception");
			try
			{
				std::cout << "Trying to create a Bureaucrat with grade of 120" << std::endl;
				Bureaucrat first("Correct", 120);
				std::cout << "Trying to create a Bureaucrat with grade of 0" << std::endl;
				Bureaucrat second("Too High", 0);
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "l_const")
		{
			print_header("Testing Constructor TooLow Exception");
			try
			{
				std::cout << "Trying to create a Bureaucrat with grade of 120" << std::endl;
				Bureaucrat first("Correct", 120);
				std::cout << "Trying to create a Bureaucrat with grade of 151" << std::endl;
				Bureaucrat second("Too Low", 151);
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "i_grade")
		{
			print_header("Testing Grade incrementor");
			try
			{
				std::cout << "Trying to create a Bureaucrat with grade of 2" << std::endl;
				Bureaucrat first("Great student", 2);
				std::cout << first << std::endl;
				std::cout << "Incrementing grade..." << std::endl;
				first.incGrade();
				std::cout << first << std::endl;
				std::cout << "Incrementing grade..." << std::endl;
				first.incGrade();
			}
			catch (std::exception & e)
			{
				std::cerr << "Error: " << e.what() << std::endl;
			}
		}
		else if (test == "d_grade")
		{
			print_header("Testing Grade decrementor");
			try
			{
				std::cout << "Trying to create a Bureaucrat with grade of 149" << std::endl;
				Bureaucrat first("Bad student", 149);
				std::cout << first << std::endl;
				std::cout << "Deccrementing grade..." << std::endl;
				first.decGrade();
				std::cout << first << std::endl;
				std::cout << "Deccrementing grade..." << std::endl;
				first.decGrade();
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
		std::cout << "h_const - Test Constructor TooHigh Exception" << std::endl;
		std::cout << "l_const - Test Constructor TooLow Exception" << std::endl;
		std::cout << "i_grade - Test Grade incrementor" << std::endl;
		std::cout << "d_grade - Test Grade decrementor" << std::endl;
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