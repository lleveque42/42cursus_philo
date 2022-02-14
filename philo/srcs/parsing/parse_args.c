/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 12:17:19 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 16:04:49 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	parse_args(int ac, char **av, t_data *data)
{
	(void)ac;
	(void)data;
	if (check_args(ac, av))
		exit(2);
	return (0);
}
