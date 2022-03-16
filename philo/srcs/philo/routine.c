/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:13:10 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/16 16:56:57 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	routine_return(t_data *data)
{
	pthread_mutex_lock(&data->stop_checker);
	if (data->stop)
	{
		pthread_mutex_unlock(&data->stop_checker);
		return (1);
	}
	pthread_mutex_unlock(&data->stop_checker);
	return (0);
}

void	status(char *status, t_philo *philo)
{
	long int	time_since_start;

	if (philo->data->stop)
		return ;
	time_since_start = get_time() - philo->data->start_time;
	if (time_since_start >= 0 && time_since_start <= 2147483647)
	{
		printf("%ld ", time_since_start);
		printf("%d %s", philo->id, status);
	}
}

void	routine_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	status("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	ft_usleep(philo->data->ttsleep);
	pthread_mutex_lock(&philo->data->write_mutex);
	status("is thinking\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
}

int	routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	pthread_mutex_lock(&philo->data->write_mutex);
	status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(&philo->data->write_mutex);
	status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	pthread_mutex_lock(&philo->data->write_mutex);
	status("is eating\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	pthread_mutex_lock(&philo->eat_mutex);
	philo->last_eat = get_time() - philo->data->start_time;
	philo->eat_count++;
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(philo->data->tteat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	routine_sleep_think(philo);
	return (routine_return(philo->data));
}
