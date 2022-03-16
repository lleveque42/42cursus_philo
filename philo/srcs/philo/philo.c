/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:22:04 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/15 18:19:47 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo(t_data *data)
{
	int	i;

	i = 0;
	init_philo(data);
	init_mutex(data);
	data->start_time = get_time();
	start_threading(data);
	// while (i < data->n_philo)
	// {
	// 	pthread_join(data->philo[i].thread, NULL);
	// 	i++;
	// }
	return (0);
}
