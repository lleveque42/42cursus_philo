/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:58:15 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/15 16:25:23 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_usleep(long int time)
{
	long int	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time)
		usleep(time / 10);
}

long int	get_time(void)
{
	long int	current_time;
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		ft_putstr_fd("Error\nPthread was not created.\n", 2);
		exit (1);
	}
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}
