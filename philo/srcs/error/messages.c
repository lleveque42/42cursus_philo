/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:11:53 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 17:28:10 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	wrong_nb_args(void)
{
	ft_putstr_fd("Error\nPhilo takes 4 or 5 arguments.\n", 2);
	return (2);
}

int	only_nb(void)
{
	ft_putstr_fd("Error\nPhilo takes only positives integers in arguments.\n", 2);
	return (2);
}

int	input_look(void)
{
	ft_putstr_fd("Error\nInput must look like this : ./philo 1 2 3 4 or ./philo +1 +2 +3 +4.\n", 2);
	return (2);
}
