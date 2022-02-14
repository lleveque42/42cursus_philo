/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:59:16 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 17:25:32 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	check_int(int ac, char **av)
{
	int	i;
	int	len;

	i = 1;
	while (i < ac)
	{
		len = check_len(av[i]);
		if (len > 10)
			return (1);
		else if (len == 10)
		{
			if (check_int_min_and_max(av[i]))
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (check_num(av[i]))
			return (only_nb());
		i++;
	}
	if (check_int(ac, av))
		return (only_nb());
	if (check_atoi(av))
		return (input_look());
	// while (av[i])
	// {
	// }
	return (0);
}
