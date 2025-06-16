/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:11:05 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:42:31 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
Bureaucrat::Bureaucrat(Bureaucrat const &origin) : _name(origin._name)
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
 */
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

/**
 * @brief	Exception thrown when the grade is too low.
 */
const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief	Increment the grade of the bureaucrat.
 * 
 * @throws	GradeTooHighException if the grade is already at the maximum (1).
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
 * @throws	GradeTooLowException if the grade is already at the minimum (150).
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
 * @brief	Overloaded output operator for Bureaucrat class.
 * 
 * @param	os The output stream to write to.
 * @param	bureaucrat The Bureaucrat object to output.
 * @return	The output stream after writing the Bureaucrat information.
 */
std::ostream	&operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}
