/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:11:05 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 15:06:23 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/**
 * @brief	Default constructor for Bureaucrat class.
 */
Bureaucrat::Bureaucrat() : _name("Unamed"), _grade(150)
{}

/**
 * @brief	Constructor for Bureaucrat class with parameters.
 * 
 * @param	name The name of the bureaucrat.
 * @param	grade The grade of the bureaucrat, must be between 1 and 150.
 * @throws	GradeTooHighException if grade is less than 1.
 * @throws	GradeTooLowException if grade is greater than 150.
 */
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name),
_grade(grade)
{
	if (_grade < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (_grade > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

/**
 * @brief	Copy constructor for Bureaucrat class.
 * 
 * @param	origin The Bureaucrat object to copy from.
 */
Bureaucrat::Bureaucrat(Bureaucrat const &origin)
{
	*this = origin;
}

/**
 * @brief	Assignment operator for Bureaucrat class.
 * 
 * @param	other The Bureaucrat object to assign from.
 * @return	A reference to the current object.
 */
Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
	{
		if (other._grade < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		if (other._grade > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}	
		this->_grade = other._grade;
	}
	return (*this);
}

/**
 * @brief	Destructor for Bureaucrat class.
 */
Bureaucrat::~Bureaucrat()
{}

/**
 * @brief	Get the name of the bureaucrat.
 * 
 * @return	The name of the bureaucrat.
 */
std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

/**
 * @brief	Get the grade of the bureaucrat.
 * 
 * @return	The grade of the bureaucrat.
 */
int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

/**
 * @brief	Exception thrown when the grade is too high.
 * 
 * @return	A const char pointer to the exception message.
 */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (over 1)");
}

/**
 * @brief	Exception thrown when the grade is too low.
 * 
 * @return	A const char pointer to the exception message.
 */
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low (under 150)");
}

/**
 * @brief	Increment the grade of the bureaucrat.
 * 
 * @throws	GradeTooHighException if the grade is already 1.
 */
void		Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else
	{
		_grade--;
	}
}

/**
 * @brief	Decrement the grade of the bureaucrat.
 * 
 * @throws	GradeTooLowException if the grade is already 150.
 */
void		Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		_grade++;
	}
}

/**
 * @brief	Sign a form if the bureaucrat's grade is high enough.
 * 
 * @param	form The form to be signed.
 * @throws	GradeTooLowException if the bureaucrat's grade is too low to sign the form.
 */
void		Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

/**
 * @brief	Execute a form if the bureaucrat's grade is high enough and the form is signed.
 * 
 * @param	form The form to be executed.
 * @throws	NotSignedException if the form is not signed.
 * @throws	GradeTooLowException if the bureaucrat's grade is too low to execute the form.
 */
void		Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

/**
 * @brief	Overloaded output operator for Bureaucrat class.
 * 
 * @param	os The output stream.
 * @param	bureaucrat The Bureaucrat object to output.
 * @return	The output stream.
 */
std::ostream	&operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
