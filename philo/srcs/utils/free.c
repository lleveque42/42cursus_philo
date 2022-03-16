/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:47:44 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/15 18:21:54 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;

	while (i < data->n_philo)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->n_philo)
	{
		pthread_join(data->philo[i].death, NULL);
		pthread_mutex_destroy(&data->philo[i].eat_mutex);
		pthread_mutex_destroy(&data->philo[i].l_fork);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	free(data->philo);
}
