/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:47:44 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/15 16:40:44 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->philo[i].eat_mutex);
		pthread_mutex_destroy(&data->philo[i].l_fork);
		pthread_join(data->philo[i].thread, NULL);
		pthread_join(data->philo[i].death, NULL);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	free(data->philo);
	exit(1);
}
