/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:53:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/17 16:57:55 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	init_mutex(t_data	*data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->write_mutex, NULL))
		return (error("Mutex was not initialized\n"));
	if (pthread_mutex_init(&data->stop_checker, NULL))
		return (error("Mutex was not initialized\n"));
	while (i < data->n_philo)
	{
		if (pthread_mutex_init(&data->philo[i].eat_mutex, NULL))
			return (error("Mutex was not initialized\n"));
		i++;
	}
	return (0);
}

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philo)
		exit(malloc_went_wrong());
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].r_fork = NULL;
		if (pthread_mutex_init(&data->philo[i].l_fork, NULL))
			return (error("Mutex was not initialized\n"));
		data->philo[i].data = data;
		data->philo[i].last_eat = 0;
		data->philo[i].eat_count = 0;
		i++;
	}
	i = 0;
	while (i < data->n_philo - 1)
	{
		data->philo[i].r_fork = &data->philo[i + 1].l_fork;
		i++;
	}
	data->philo[i].r_fork = &data->philo[0].l_fork;
	return (0);
}
