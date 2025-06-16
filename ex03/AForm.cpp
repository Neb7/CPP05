/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:08:42 by benpicar          #+#    #+#             */
/*   Updated: 2025/05/21 18:48:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/**
 * @brief	Default constructor for AForm class.
 */
AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150),
_gradeToExecute(150)
{}

/**
 * @brief	Constructor for AForm class with parameters.
 * 
 * @param	name The name of the form.
 * @param	gradeToSign The grade required to sign the form.
 * @param	gradeToExecute The grade required to execute the form.
 * @throws	GradeTooHighException if gradeToSign or gradeToExecute is less than 1.
 * @throws	GradeTooLowException if gradeToSign or gradeToExecute is greater than 150.
 */
AForm::AForm(std::string const name, int gradeToSign, int gradeToExecute) :
_name(name), _signed(false), _gradeToSign(gradeToSign), 
_gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}
	if (_gradeToSign > 150 || this->_gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

/**
 * @brief	Copy constructor for AForm class.
 * 
 * @param	origin The AForm object to copy from.
 */
AForm::AForm(AForm const &origin) : _name(origin._name),
_gradeToSign(origin._gradeToSign), _gradeToExecute(origin._gradeToExecute)
{
	this->_signed = origin._signed;
}

/**
 * @brief	Assignment operator for AForm class.
 * 
 * @param	other The AForm object to assign from.
 * @return	A reference to the current object.
 */
AForm	&AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

/**
 * @brief	Destructor for AForm class.
 */
AForm::~AForm()
{}

/**
 * @brief	Get the name of the form.
 * 
 * @return	The name of the form.
 */
std::string	AForm::getName() const
{
	return (this->_name);
}

/**
 * @brief	Get the signed status of the form.
 * 
 * @return	True if the form is signed, false otherwise.
 */
bool		AForm::getSigned() const
{
	return (this->_signed);
}

/**
 * @brief	Get the grade required to sign the form.
 * 
 * @return	The grade required to sign the form.
 */
int			AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

/**
 * @brief	Get the grade required to execute the form.
 * 
 * @return	The grade required to execute the form.
 */
int			AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

/**
 * @brief	Sign the form if the bureaucrat's grade is high enough.
 * 
 * @param	bureaucrat The bureaucrat signing the form.
 * @throws	GradeTooLowException if the bureaucrat's grade is too low to sign the form.
 */
void		AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

/**
 * @brief	Exception thrown when the grade is too hight.
 * 
 * @return	A string indicating that the grade is too low.
 */
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high (over 1)");
}

/**
 * @brief	Exception thrown when the grade is too low.
 * 
 * @return	A string indicating that the grade is too low.
 */
const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

/**
 * @brief	Exception thrown when the form is not signed.
 * 
 * @return	A string indicating that the form is not signed.
 */
const char	*AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed.");
}

/**
 * @brief	Overloaded output operator for AForm class.
 * 
 * @param	os The output stream.
 * @param	form The AForm object to output.
 * @return	The output stream after writing the AForm object.
 */
std::ostream	&operator<<(std::ostream &os, AForm const &form)
{
	os << "Form: " << form.getName() << ", Signed: " << (form.getSigned() ? "Yes" : "No")
	   << ", Grade to sign: " << form.getGradeToSign()
	   << ", Grade to execute: " << form.getGradeToExecute();
	return (os);
}
