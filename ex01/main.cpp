/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:03 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:54:55 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

#define ORANGE	"\033[1;33m"
#define NC		"\033[0m"

int main(void)
{
	Bureaucrat	Bob("Bob", 1);
	Bureaucrat	Jojo("Jojo", 150);
	Form		pool("Pool", 50, 20);
	
	std::cout << ORANGE << "/*****   TEST  *****/" << NC << std::endl;
	std::cout << Bob << std::endl << Jojo << std::endl;
	try
	{
		std::cout << pool << std::endl;
		Jojo.signForm(pool);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	std::cout << std::endl << ORANGE << "/*****   TEST VALID  *****/" 
			  << NC << std::endl;
	try
	{
		Bureaucrat	bureaucrat3("Bureaucrat3", 100);
		Bob.signForm(pool);
		std::cout << pool << std::endl;
		std::cout << bureaucrat3 << std::endl;
		bureaucrat3.incrementGrade();
		std::cout << bureaucrat3 << std::endl;
		bureaucrat3.decrementGrade();
		std::cout << bureaucrat3 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}