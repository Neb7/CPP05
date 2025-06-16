/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:03 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:38:45 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define ORANGE	"\033[1;33m"
#define NC		"\033[0m"

int main(void)
{
	std::cout << ORANGE << "/*****   TEST  *****/" << NC << std::endl;
	try
	{
		Bureaucrat	bureaucrat("Bob", 1);
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	try
	{;
		Bureaucrat	bureaucrat2("Paul", 150);
		std::cout << bureaucrat2 << std::endl;
		bureaucrat2.decrementGrade();
		std::cout << bureaucrat2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}

	std::cout << std::endl << ORANGE << "/*****   TEST VALID  *****/" 
			  << NC << std::endl;
	try
	{
		Bureaucrat	bureaucrat3("Pierre", 100);
		std::cout << bureaucrat3 << std::endl;
		bureaucrat3.incrementGrade();
		std::cout << bureaucrat3 << std::endl;
		bureaucrat3.decrementGrade();
		std::cout << bureaucrat3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}