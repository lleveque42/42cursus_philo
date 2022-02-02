/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:48:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/02 13:00:01 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include

typedef struct s_data
{
	int	n_philo;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	n_eat;
} t_data;

int	check_args(char **av);
int	parse_args(int ac, char **av, t_data *data);

#endif PHILO_H


