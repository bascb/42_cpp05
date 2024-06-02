/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:05:48 by bcastelo          #+#    #+#             */
/*   Updated: 2024/06/02 18:52:34 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

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
			std::cout << std::endl;
			std::cout << "Usage example:" << std::endl;
			std::cout << std::endl;
			std::cout << argv[0] << " mat" << std::endl;
			std::cout << std::endl;
			return (0);
		}
		else if (test == "const")
		{
			print_header("Testing constructor and object print");
			Bureaucrat first("Original", 120);
			Bureaucrat second(first);
			Bureaucrat third("Other", 50);

			std::cout << "First: " << first << std::endl;
			std::cout << "Second: " << second << std::endl;
			std::cout << "Third: " << third << std::endl;

			third = first;
			std::cout << "Third: " << third << std::endl;
		}
	}
	{
		print_header("Subject");
		std::cout << "Subject tests" << std::endl;
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