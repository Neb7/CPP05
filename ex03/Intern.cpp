/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:50:16 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:58:58 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/**
 * @brief	Default constructor for Intern class.
 */
Intern::Intern()
{}

/**
 * @brief	Copy constructor for Intern class.
 * 
 * @param	origin The Intern object to copy from.
 */
Intern::Intern(const Intern &origin)
{
	*this = origin;
}

/**
 * @brief	Assignment operator for Intern class.
 * 
 * @param	other The Intern object to assign from.
 * @return	A reference to the current object.
 */
Intern	&Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

/**
 * @brief	Destructor for Intern class.
 */
Intern::~Intern()
{}

/**
 * @brief	Private method to create a RobotomyRequestForm.
 * 
 * @param	target The target for the form.
 * @return	A pointer to the newly created RobotomyRequestForm.
 */
AForm	*Intern::createRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

/**
 * @brief	Private method to create a PresidentialPardonForm.
 * 
 * @param	target The target for the form.
 * @return	A pointer to the newly created PresidentialPardonForm.
 */
AForm	*Intern::createPresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

/**
 * @brief	Private method to create a ShrubberyCreationForm.
 * 
 * @param	target The target for the form.
 * @return	A pointer to the newly created ShrubberyCreationForm.
 */
AForm	*Intern::createShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

/**
 * @brief	Method to create a form based on the form name and target.
 * 
 * @param	formName The name of the form to create.
 * @param	target The target for the form.
 * @return	A pointer to the newly created form.
 * @throws	FormNotFoundException if the form name is not recognized.
 * @throws	std::invalid_argument if the target is empty.
 */
AForm	*Intern::makeForm(std::string formName, std::string target)
{
	std::string	formNames[3] = {"robotomy request", "presidential pardon",
		"shrubbery creation"};
	int			i;
	AForm		*(Intern::*f[3])(std::string) = {
					&Intern::createRobotomyRequestForm,
					&Intern::createPresidentialPardonForm,
					&Intern::createShrubberyCreationForm};
		
	if (target.empty())
	{
		throw std::invalid_argument("Intern : Target cannot be empty.");
	}
	for (i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*f[i])(target));
		}
	}
	throw Intern::FormNotFoundException();
	return (NULL);
}

/**
 * @brief	Exception thrown when a form is not found.
 * 
 * @return	A const char pointer to the exception message.
 */
const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Intern: Form not found");
}
