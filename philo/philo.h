/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:48:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/13 16:08:40 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t *r_fork;
}	t_philo;

typedef struct s_data
{
	int		n_philo;
	int		ttdie;
	int		tteat;
	int		ttsleep;
	int		n_eat;
	t_philo	*philo;
} t_data;

int		ft_isdigit(char c);
int		check_num(char *av);
int		check_len(char *s);
int		check_atoi(char **av);
int		wrong_nb_args(void);
int		only_nb(void);
int		input_look(void);
int		time_to_long(void);
int		malloc_went_wrong(void);
void	ft_putstr_fd(char *s, int fd);
int		check_int_min_and_max(char *s);
int		check_args(int ac, char **av);
int		ft_atoi(char *nptr);
int		parse_args(int ac, char **av, t_data *data);
int		philo(t_data *data);
void	init_philo(t_data *data);
void	start_routine(t_data *data);

#endif


