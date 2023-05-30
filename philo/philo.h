/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-prad <vde-prad@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:26:03 by vde-prad          #+#    #+#             */
/*   Updated: 2023/05/30 20:58:57 by vde-prad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
/***************** INCLUDES *******************/
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

/**************** DEFINITIONS *****************/
# define SLEEP "%ld ms %d is sleeping\n"
# define THINK "%ld ms %d is thinking\n"
# define EAT "%ld ms %d is eating\n"
# define FORK "%ld ms %d has taken a fork\n"

typedef struct s_philo{
	pthread_t		tid;
	pthread_mutex_t	fork1;
	pthread_mutex_t	*fork2;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	last_eat_mutex;
	time_t			last_eat;
	time_t			stime;
	int				index;
	int				finish;
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				n_lunches;
}	t_philo;

typedef struct s_data{
	time_t			stime;
	t_philo			*philos;
	int				n_philo;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				n_lunches;
}	t_data;

/***************** FUNCTIONS ******************/
// main.c
void	ft_sleep(time_t t, int option);
time_t	ft_time(time_t option);
// init.c
int		ft_input(int argc, char **argv, t_data *data);
int		ft_init_philosophers(t_data *data);
// utils.c
int		ft_atoi(const char *str);
int		ft_check_args(char *arg);
// threads_utils.c
int		ft_inanition(t_philo *philos);
int		ft_drop_fork(t_philo *philos);
int		ft_take_fork(t_philo *philos);
// philochecker.c
int		ft_check_philos(t_data *data);
int		ft_check_finish(t_philo *philos, int n_philos);
#endif