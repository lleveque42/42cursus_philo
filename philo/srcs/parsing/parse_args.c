/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:19 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/15 14:10:52 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	get_param(int ac, char **av, t_data *data)
{
	int	i;

	i = 2;
	while (i < 5)
	{
		if (ft_atoi(av[i]) > 2147483647 / 1000 || ft_atoi(av[i]) == 0)
			return (time_to_long());
		i++;
	}
	data->n_philo = ft_atoi(av[1]);
	data->ttdie = ft_atoi(av[2]);
	data->tteat = ft_atoi(av[3]);
	data->ttsleep = ft_atoi(av[4]);
	data->n_eat = 2147483647;
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	return (0);
}

int	parse_args(int ac, char **av, t_data *data)
{
	(void)ac;
	(void)data;
	if (check_args(ac, av))
		exit(1);
	if (get_param(ac, av, data))
		exit(1);
	return (0);
}
