/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:45:03 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:59:42 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef INTERN_HPP
# define INTERN_HPP

# include <ostream>
# include <stdexcept>
# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

/**
 * @brief	Intern class represents an intern who can create forms based on the
 * 			form name and target provided. It can create specific forms like
 * 			RobotomyRequestForm, PresidentialPardonForm, and ShrubberyCreationForm.
 */
class Intern
{
	private:
		AForm	*createRobotomyRequestForm(std::string target);
		AForm	*createPresidentialPardonForm(std::string target);
		AForm	*createShrubberyCreationForm(std::string target);

	public:
		Intern();
		Intern(const Intern &origin);
		Intern	&operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(std::string formName, std::string target);

		class FormNotFoundException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

#endif