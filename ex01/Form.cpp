/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:08:42 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/05 14:51:11 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/**
 * @brief	Default constructor for Form class.
 */
Form::Form() : _name("default"), _signed(false), _gradeToSign(150),
_gradeToExecute(150)
{}

/**
 * @brief	Constructor for Form class with parameters.
 * 
 * @param	name The name of the form.
 * @param	gradeToSign The grade required to sign the form.
 * @param	gradeToExecute The grade required to execute the form.
 * @throws	GradeTooHighException if gradeToSign or gradeToExecute is less than 1.
 * @throws	GradeTooLowException if gradeToSign or gradeToExecute is greater than 150.
 */
Form::Form(std::string const name, int gradeToSign, int gradeToExecute) :
_name(name), _signed(false), _gradeToSign(gradeToSign), 
_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}
	if (_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
}

/**
 * @brief	Copy constructor for Form class.
 * 
 * @param	origin The Form object to copy from.
 */
Form::Form(Form const &origin) : _name(origin._name),
_gradeToSign(origin._gradeToSign), _gradeToExecute(origin._gradeToExecute)
{
	this->_signed = origin._signed;
}

/**
 * @brief	Assignment operator for Form class.
 * 
 * @param	other The Form object to assign from.
 * @return	A reference to the current object.
 */
Form	&Form::operator=(Form const &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

/**
 * @brief	Destructor for Form class.
 */
Form::~Form()
{}

/**
 * @brief	Overloaded output operator for Form class.
 * 
 * @param	os The output stream.
 * @param	form The Form object to output.
 * @return	The output stream.
 */
std::string	Form::getName() const
{
	return (this->_name);
}

/**
 * @brief	Get the signed status of the form.
 * 
 * @return	True if the form is signed, false otherwise.
 */
bool		Form::getSigned() const
{
	return (this->_signed);
}

/**
 * @brief	Get the grade required to sign the form.
 * 
 * @return	The grade required to sign the form.
 */
int			Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

/**
 * @brief	Get the grade required to execute the form.
 * 
 * @return	The grade required to execute the form.
 */
int			Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

/**
 * @brief	Sign the form if the bureaucrat's grade is high enough.
 * 
 * @param	bureaucrat The bureaucrat who is signing the form.
 * @throws	GradeTooLowException if the bureaucrat's grade is too low to sign the form.
 */
void		Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	this->_signed = true;
}

/**
 * @brief	Exception thrown when the grade is too high.
 */
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (over 1)");
}

/**
 * @brief	Exception thrown when the grade is too low.
 */
const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief	Overloaded output operator for Form class.
 * 
 * @param	os The output stream.
 * @param	form The Form object to output.
 * @return	The output stream with the form's details.
 */
std::ostream	&operator<<(std::ostream &os, Form const &form)
{
	os << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return (os);
}
