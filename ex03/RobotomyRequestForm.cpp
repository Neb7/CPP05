/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:49:56 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:37:47 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/**
 * @brief	Default constructor for RobotomyRequestForm class.
 */
RobotomyRequestForm::RobotomyRequestForm() :
AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

/**
 * @brief	Constructor for RobotomyRequestForm class with target parameter.
 * 
 * @param	target The target to be robotomized.
 * @throws	std::invalid_argument if the target is empty.
 */
RobotomyRequestForm::RobotomyRequestForm(std::string const target) :
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (target.empty())
	{
		throw std::invalid_argument("Target cannot be empty.");
	}
}

/**
 * @brief	Copy constructor for RobotomyRequestForm class.
 * 
 * @param	origin The RobotomyRequestForm object to copy from.
 */
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &origin)
: AForm(origin), _target(origin._target)
{
	*this = origin;
}

/**
 * @brief	Assignment operator for RobotomyRequestForm class.
 * 
 * @param	other The RobotomyRequestForm object to assign from.
 * @return	A reference to the current object.
 * @throws	std::invalid_argument if the target is empty.
 */
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
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
 * @brief	Destructor for RobotomyRequestForm class.
 */
RobotomyRequestForm::~RobotomyRequestForm()
{}

/**
 * @brief	Get the target of the RobotomyRequestForm.
 * 
 * @return	The target as a string.
 */
std::string		RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

/**
 * @brief	Execute the robotomy request form.
 * 
 * @param	executor The bureaucrat executing the form.
 * @throws	GradeTooLowException if the executor's grade is too low to execute the form.
 * @throws	NotSignedException if the form is not signed.
 */
void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getGradeToExecute() < executor.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		throw AForm::NotSignedException();
	}
	std::cout << "*VRRRRRRRRRRRRRRRRRRRRRR* 🔩🔧" << std::endl;
	if (rand() % 2)
	{
		std::cout << this->_target << " has been robotomized successfully 👌"
				  << std::endl;
	}
	else
	{
		std::cout << this->_target << " failed to be robotomized 👎" << std::endl;
	}
}
