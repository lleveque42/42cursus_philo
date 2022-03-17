/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:58:15 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/17 18:30:21 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	status(char *status, t_philo *philo)
{
	long int	time_since_start;

	pthread_mutex_lock(&philo->data->stop_checker);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->stop_checker);
		return ;
	}
	pthread_mutex_unlock(&philo->data->stop_checker);
	time_since_start = get_time() - philo->data->start_time;
	if (time_since_start >= 0 && time_since_start <= 2147483647)
	{
		printf("%ld ", time_since_start);
		printf("%d %s", philo->id, status);
	}
}

void	ft_usleep(long int time, t_data *data)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
	{
		pthread_mutex_lock(&data->stop_checker);
		if (data->stop)
		{
			pthread_mutex_unlock(&data->stop_checker);
			return ;
		}
		pthread_mutex_unlock(&data->stop_checker);
		usleep(time / 1000);
	}
}

long int	get_time(void)
{
	long int	current_time;
	t_timeval	time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}
