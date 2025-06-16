/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:12:52 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:34:43 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
 
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

/**
 * @brief	PresidentialPardonForm class represents a form that allows a bureaucrat
 *          to pardon a target. It inherits from AForm and requires a specific grade
 *          to sign and execute.
 */
class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &origin);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &other);
		virtual ~PresidentialPardonForm();

		std::string				getTarget() const;

		virtual void			execute(Bureaucrat const &executor) const;
};

#endif
