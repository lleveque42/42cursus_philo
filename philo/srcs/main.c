/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:47:49 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/14 18:01:35 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (wrong_nb_args());
	parse_args(ac, av, &data);
	philo(&data);
	free(data.philo);
	pthread_mutex_destroy(&data.eat_mutex);
	pthread_mutex_destroy(&data.write_mutex);
	return (0);
}
