/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:03:04 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/13 16:37:55 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_num(char *av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		if (!(ft_isdigit(av[i]) || (av[i] >= 7 && av[i] <= 13) || av[i] == ' '
				|| av[i] == '+'))
			return (1);
		i++;
	}
	return (0);
}

int	check_atoi(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] && ((av[i][j] >= 7 && av[i][j] <= 13)
				|| av[i][j] == ' '))
			j++;
		if (av[i][j] && av[i][j] == '+')
			j++;
		if (!av[i][j])
			return (1);
		while (av[i][j] && ft_isdigit(av[i][j]))
			j++;
		while (av[i][j] && ((av[i][j] >= 7 && av[i][j] <= 13)
				|| av[i][j] == ' '))
			j++;
		if (av[i][j] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_len(char *s)
{
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (s[j] && (s[j] == ' ' || (s[j] >= 7 && s[j] <= 13)))
		j++;
	if (s[j] && s[j] == '+')
		j++;
	while (ft_isdigit(s[j]))
	{
		len++;
		j++;
	}
	return (len);
}

int	check_int_min_and_max(char *s)
{
	int			i;
	long long	result;
	int			int_max;

	i = 0;
	result = 0;
	int_max = 2147483647;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - 48);
		i++;
	}
	if (s[0] == '-' && (result - 1) > int_max)
		return (1);
	else if (s[0] != '-' && result > int_max)
		return (1);
	return (0);
}
