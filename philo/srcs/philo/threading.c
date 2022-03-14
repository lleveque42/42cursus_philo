/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threading.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:50:20 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/14 18:47:21 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*threading(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 1)
		ft_usleep(philo->data->tteat / 10);
	while (1)
		routine(philo);
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
			ft_exit("Error\nPthread was not created.\n");
		i++;
	}
}
