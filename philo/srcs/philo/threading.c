/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:50:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/15 16:24:47 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*check_death(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	while (1)
	{
		pthread_mutex_lock(&philo->eat_mutex);
		if ((get_time() - philo->last_eat - philo->data->start_time) >
			philo->data->ttdie)
		{
			if (philo->eat_count == philo->data->n_eat)
				return (NULL);
			pthread_mutex_lock(&philo->data->write_mutex);
			printf("%ld %d died\n", get_time() - philo->data->start_time, philo->id);
			ft_exit(philo->data);
		}
		pthread_mutex_unlock(&philo->eat_mutex);
	}
}

void	*threading(void *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->tteat / 10);
	pthread_create(&philo->death, NULL, check_death, philo);
	while (i < philo->data->n_eat)
	{
		routine(philo);
		i++;
	}
	pthread_detach(philo->death);
	return (NULL);
}

void	start_threading(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (pthread_create(&data->philo[i].thread, NULL, threading,
				&data->philo[i]))
		{
			ft_putstr_fd("Error\nPthread was not created.\n", 2);
			exit (1);
		}
		i++;
	}
}
