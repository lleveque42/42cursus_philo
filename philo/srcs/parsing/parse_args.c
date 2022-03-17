/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:19 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/17 17:24:04 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	get_param(int ac, char **av, t_data *data)
{
	int	i;

	i = 2;
	data->n_philo = ft_atoi(av[1]);
	if (!data->n_philo)
		return (error("At least one philo is required.\n"));
	data->ttdie = ft_atoi(av[2]);
	data->tteat = ft_atoi(av[3]);
	data->ttsleep = ft_atoi(av[4]);
	if (!data->ttdie || !data->tteat || !data->ttsleep)
		return (error("Invalid arguments.\n"));
	data->n_eat = -1;
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	data->stop = 0;
	return (0);
}

int	parse_args(int ac, char **av, t_data *data)
{
	if (check_args(ac, av))
		return (1);
	if (get_param(ac, av, data))
		return (1);
	return (0);
}
