/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:50:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/17 17:59:19 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	stop(t_data	*data, int i)
{
	pthread_mutex_unlock(&data->philo[i].eat_mutex);
	pthread_mutex_lock(&data->write_mutex);
	status("died\n", &data->philo[i]);
	pthread_mutex_unlock(&data->write_mutex);
	pthread_mutex_lock(&data->stop_checker);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_checker);
}

void	*check_death(void *data_void)
{
	int		i;
	t_data	*data;

	data = (t_data *)data_void;
	while (1)
	{
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&data->philo[i].eat_mutex);
			if ((get_time() - data->philo[i].last_eat - data->start_time)
				> data->ttdie)
			{
				if (data->n_eat != 0 && data->philo[i].eat_count == data->n_eat)
				{
					pthread_mutex_unlock(&data->philo[i].eat_mutex);
					return (NULL);
				}
				stop(data, i);
				return (NULL);
			}
			pthread_mutex_unlock(&data->philo[i].eat_mutex);
			i++;
		}
	}
}

void	*threading(void *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->tteat / 10, philo->data);
	while (1)
	{
		if (philo->data->n_eat != -1 && i >= philo->data->n_eat)
			break ;
		pthread_mutex_lock(&philo->data->stop_checker);
		if (philo->data->stop)
		{
			pthread_mutex_unlock(&philo->data->stop_checker);
			break ;
		}
		pthread_mutex_unlock(&philo->data->stop_checker);
		if (routine(philo))
			break ;
		i++;
	}
	return (NULL);
}

int	start_threading(t_data *data)
{
	int	i;

	i = 0;
	if (!data->n_eat)
		return (0);
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, threading,
				&data->philo[i]))
			return (error("Pthread was not created.\n"));
		i++;
	}
	if (pthread_create(&data->death_checker, NULL, check_death, data))
		return (error("Pthread was not created.\n"));
	return (0);
}
