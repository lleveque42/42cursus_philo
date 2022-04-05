/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:13:10 by lleveque          #+#    #+#             */
/*   Updated: 2022/04/05 16:19:37 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	lock_first_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(&philo->l_fork);
}

void	lock_second_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(&philo->l_fork);
	else
		pthread_mutex_lock(philo->r_fork);
}

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

void	routine_sleep_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->write_mutex);
	status("is sleeping\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	ft_usleep(philo->data->ttsleep, philo->data);
	pthread_mutex_lock(&philo->data->write_mutex);
	status("is thinking\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	if (philo->data->tteat >= philo->data->ttsleep
		&& philo->data->n_philo % 2 == 1)
		ft_usleep((philo->data->tteat), philo->data);
}

int	routine(t_philo *philo)
{
	lock_first_fork(philo);
	pthread_mutex_lock(&philo->data->write_mutex);
	status("has taken a fork\n", philo);
	pthread_mutex_unlock(&philo->data->write_mutex);
	if (philo->data->n_philo <= 1)
	{
		pthread_mutex_unlock(&philo->l_fork);
		return (1);
	}
	lock_second_fork(philo);
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
	ft_usleep(philo->data->tteat, philo->data);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
	routine_sleep_think(philo);
	return (routine_return(philo->data));
}
