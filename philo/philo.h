/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleveque <lleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:48:32 by lleveque          #+#    #+#             */
/*   Updated: 2022/03/16 15:53:21 by lleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct timeval	t_timeval;

struct s_philo
{
	int				id;
	int				eat_count;
	long int		last_eat;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	eat_mutex;
	t_data			*data;
};

struct s_data
{
	int				n_philo;
	int				ttdie;
	int				tteat;
	int				ttsleep;
	int				n_eat;
	int				stop;
	long int		start_time;
	pthread_t		death_checker;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	stop_checker;
	t_philo			*philo;
};

int			ft_isdigit(char c);
int			check_num(char *av);
int			check_len(char *s);
int			check_atoi(char **av);
int			wrong_nb_args(void);
int			only_nb(void);
int			input_look(void);
int			time_to_long(void);
int			malloc_went_wrong(void);
void		ft_free(t_data *data);
void		unlock_mutex(t_data *data);
void		destroy_mutex(t_data *data);
void		ft_putstr_fd(char *s, int fd);
int			check_int_min_and_max(char *s);
int			check_args(int ac, char **av);
int			ft_atoi(char *nptr);
int			parse_args(int ac, char **av, t_data *data);
int			philo(t_data *data);
long int	get_time(void);
void		ft_usleep(long int time);
void		init_philo(t_data *data);
void		init_mutex(t_data	*data);
void		start_threading(t_data *data);
int			routine(t_philo *philo);
void		routine_sleep_think(t_philo *philo);
void		status(char *status, t_philo *philo);

#endif
