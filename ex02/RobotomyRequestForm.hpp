/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benpicar <benpicar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 11:47:20 by benpicar          #+#    #+#             */
/*   Updated: 2025/06/09 13:40:17 by benpicar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <stdexcept>
# include <cstdlib>
# include "AForm.hpp"

/**
 * @brief	RobotomyRequestForm class represents a form that allows a bureaucrat
 *          to request a robotomy on a target. It inherits from AForm and requires
 *          a specific grade to sign and execute.
 */
class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const &origin);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &other);
		virtual ~RobotomyRequestForm();

		std::string			getTarget() const;

		void				execute(Bureaucrat const &executor) const;
};

#endif
