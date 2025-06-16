/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:14:07 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:37:11 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/**
 * @brief	Default constructor for PresidentialPardonForm class.
 */
PresidentialPardonForm::PresidentialPardonForm() :
AForm("PresidentialPardonForm", 25, 5), _target("default")
{}

/**
 * @brief	Constructor for PresidentialPardonForm class with target parameter.
 * 
 * @param	target The target to be pardoned.
 * @throws	std::invalid_argument if the target is empty.
 */
PresidentialPardonForm::PresidentialPardonForm(std::string const target) :
AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (target.empty())
	{
		throw std::invalid_argument("Target cannot be empty.");
	}
}

/**
 * @brief	Copy constructor for PresidentialPardonForm class.
 * 
 * @param	origin The PresidentialPardonForm object to copy from.
 */
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &origin)
: AForm(origin), _target(origin._target)
{
	*this = origin;
}

/**
 * @brief	Assignment operator for PresidentialPardonForm class.
 * 
 * @param	other The PresidentialPardonForm object to assign from.
 * @return	A reference to the current object.
 * @throws	std::invalid_argument if the target is empty.
 */
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm 
	const &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		if (other._target.empty())
		{
			throw std::invalid_argument("Target cannot be empty.");
		}
		this->_target = other._target;
	}
	return (*this);
}

/**
 * @brief	Destructor for PresidentialPardonForm class.
 */
PresidentialPardonForm::~PresidentialPardonForm()
{}

/**
 * @brief	Get the target of the PresidentialPardonForm.
 * 
 * @return	The target as a string.
 */
std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

/**
 * @brief	Execute the PresidentialPardonForm.
 * 
 * @param	executor The bureaucrat executing the form.
 * @throws	GradeTooLowException if the executor's grade is too low to execute
 * 			the form.
 * @throws	NotSignedException if the form is not signed.
 */	
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		throw AForm::NotSignedException();
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
}
