/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:47:44 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/17 19:41:02 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->stop_checker);
	pthread_mutex_destroy(&data->write_mutex);
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philo[i].eat_mutex);
		pthread_mutex_destroy(&data->philo[i].l_fork);
		i++;
	}
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	pthread_join(data->death_checker, NULL);
	while (i < data->n_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	destroy_mutex(data);
	free(data->philo);
}
