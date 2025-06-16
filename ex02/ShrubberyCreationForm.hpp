/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:57:50 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:41:37 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <stdexcept>
# include <fstream>
# include "AForm.hpp"

/**
 * @brief	ShrubberyCreationForm class represents a form that allows a bureaucrat
 *          to create a shrubbery at a specified target location. It inherits from AForm
 *          and requires a specific grade to sign and execute.
 */
class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(ShrubberyCreationForm const &origin);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &other);
		virtual ~ShrubberyCreationForm();

		std::string				getTarget() const;

		void					execute(Bureaucrat const &executor) const;
};

#endif
