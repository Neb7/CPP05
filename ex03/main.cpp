/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:03 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/13 15:06:15 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#define ORANGE	"\033[1;33m"
#define NC		"\033[0m"

int main(void)
{
	Bureaucrat	Bob("Bob", 1);
	Bureaucrat	Jojo("Jojo", 150);
	AForm		*form[3];
	Intern		intern;
	
	try
	{
		form[0] = intern.makeForm("random request", "false");
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	
	try
	{
		form[0] = intern.makeForm("robotomy request", "door");
		form[1] = intern.makeForm("presidential pardon", "Jean-eud");
		form[2] = intern.makeForm("shrubbery creation", "garden");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << ORANGE << "/*****   TEST  *****/" << NC << std::endl;
	std::cout << Bob << std::endl << Jojo << std::endl;
	try
	{
		Bob.executeForm(*form[0]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bob.signForm(*form[0]);
		Jojo.executeForm(*form[0]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl << ORANGE << "/*****   TEST VALID  *****/" 
			  << NC << std::endl;
	try
	{
		Bob.signForm(*form[0]);
		Bob.executeForm(*form[0]);
		Bob.signForm(*form[1]);
		Bob.executeForm(*form[1]);
		Bob.signForm(*form[2]);
		Bob.executeForm(*form[2]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Bob.executeForm(*form[0]);
	Bob.executeForm(*form[0]);
	Bob.executeForm(*form[0]);
	Bob.executeForm(*form[0]);
	Bob.executeForm(*form[0]);
	Bob.executeForm(*form[0]);
	Bob.executeForm(*form[0]);
	if (form[0])
		delete form[0];
	if (form[1])
		delete form[1];
	if (form[2])
		delete form[2];
	return (0);
}