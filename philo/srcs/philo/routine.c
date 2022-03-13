/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:50:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/13 16:22:33 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	printf("test : philo[%d]\n", philo->id);
	return (NULL);
}

void	start_routine(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		if (data->philo[i].id % 2 == 0)
			pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		usleep(10000);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		if (data->philo[i].id % 2 == 1)
			pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		usleep(10000);
		i++;
	}
}
