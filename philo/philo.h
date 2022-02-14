/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:48:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/02/14 17:34:40 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_data
{
	int	n_philo;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	n_eat;
} t_data;

int		ft_isdigit(char c);
int		check_num(char *av);
int		check_len(char *s);
int		check_atoi(char **av);
int		wrong_nb_args(void);
int		only_nb(void);
int		input_look(void);
void	ft_putstr_fd(char *s, int fd);
int		check_int_min_and_max(char *s);
int		check_args(int ac, char **av);
int		parse_args(int ac, char **av, t_data *data);

#endif


