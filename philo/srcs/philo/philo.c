/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:22:04 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/17 16:34:28 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo(t_data *data)
{
	int	i;

	i = 0;
	if (init_philo(data))
		return (1);
	if (init_mutex(data))
		return (1);
	data->start_time = get_time();
	if (start_threading(data))
		return (1);
	return (0);
}
