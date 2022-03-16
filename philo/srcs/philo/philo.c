/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:22:04 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/16 15:12:43 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	philo(t_data *data)
{
	int	i;

	i = 0;
	init_philo(data);
	init_mutex(data);
	data->start_time = get_time();
	start_threading(data);
	return (0);
}
