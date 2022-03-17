/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:47:49 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/17 19:45:27 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo(t_data *data)
{
	int	i;

	i = 0;
	if (init_philo(data))
		return (1);
	if (init_mutex(data))
		return (1);
	data->start_time = get_time();
	if (start_threading(data))
	{
		ft_free(data);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (wrong_nb_args());
	if (parse_args(ac, av, &data))
		return (1);
	if (philo(&data))
		return (1);
	ft_free(&data);
	return (0);
}
