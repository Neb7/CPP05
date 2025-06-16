/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:00:22 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:41:08 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/**
 * @brief	Default constructor for ShrubberyCreationForm class.
 */
ShrubberyCreationForm::ShrubberyCreationForm() : 
AForm("ShrubberyCreationForm", 145, 137), _target("default")
{}

/**
 * @brief	Constructor for ShrubberyCreationForm class with target parameter.
 * 
 * @param	target The target for the shrubbery creation.
 * @throws	std::invalid_argument if the target is empty.
 */
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : 
AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (target.empty())
	{
		throw std::invalid_argument("Target cannot be empty.");
	}
}

/**
 * @brief	Copy constructor for ShrubberyCreationForm class.
 * 
 * @param	origin The ShrubberyCreationForm object to copy from.
 */
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &origin)
: AForm(origin), _target(origin._target)
{
	*this = origin;
}

/**
 * @brief	Assignment operator for ShrubberyCreationForm class.
 * 
 * @param	other The ShrubberyCreationForm object to assign from.
 * @return	A reference to the current object.
 * @throws	std::invalid_argument if the target is empty.
 */
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm
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
 * @brief	Destructor for ShrubberyCreationForm class.
 */
ShrubberyCreationForm::~ShrubberyCreationForm()
{}

/**
 * @brief	Get the target of the ShrubberyCreationForm.
 * 
 * @return	The target as a string.
 */
std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

/**
 * @brief	Execute the ShrubberyCreationForm.
 * 
 * @param	executor The bureaucrat executing the form.
 * @throws	GradeTooLowException if the executor's grade is too low to execute the form.
 * @throws	NotSignedException if the form is not signed.
 * @throws	std::ios_base::failure if there is an error opening the file.
 */
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename = this->_target + "_shrubbery";

	if (this->getGradeToExecute() < executor.getGrade())
	{
		throw AForm::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		throw AForm::NotSignedException();
	}
	else
	{
		std::ofstream outFile(filename.c_str());
		if (!outFile)
		{
			throw std::ios_base::failure("Error opening file: " + filename);
			return;
		}
		outFile << "            .        +          .      .          ." << std::endl
				<< "     .            _        .                    ." << std::endl
				<< "  ,              /;-._,-.____        ,-----.__" << std::endl
				<< " ((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl
				<< "  `                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl
				<< "                      ,    `./  \\:. `.   )==-'  ." << std::endl
				<< "   .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl
				<< ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl
				<< "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl
				<< "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl
				<< "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl
				<< "              \\:  `  X` _| _,\\/'   .-'" << std::endl
				<< ".               \":._:`\\____  /:'  /      .           ." << std::endl
				<< "                    \\::.  :\\/:'  /              +" << std::endl
				<< "   .                 `.:.  /:'  }      ." << std::endl
				<< "           .           ):_(:;   \\           ." << std::endl
				<< "                      /:. _/ ,  |" << std::endl
				<< "                   . (|::.     ,`                  ." << std::endl
				<< "     .                |::.    {\\" << std::endl
				<< "                      |::.\\  \\ `." << std::endl
				<< "                      |:::(\\    |" << std::endl
				<< "              O       |:::/{ }  |                  (o" << std::endl
				<< "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl
				<< "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
		outFile.close();
	}
}
