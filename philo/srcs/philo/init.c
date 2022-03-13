/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 13:53:41 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/13 15:04:10 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo)  * data->n_philo);
	if (!data->philo)
		exit(malloc_went_wrong());
	while (i < data->n_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].r_fork = NULL;
		pthread_mutex_init(&data->philo[i].l_fork, NULL);
		i++;
	}
	i = 0;
	while (i < data->n_philo - 1)
	{
		data->philo[i].r_fork = &data->philo[i + 1].l_fork;
		i++;
	}
	data->philo[i].r_fork = &data->philo[0].l_fork;
}
