/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:30:15 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 08:30:15 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*====string.h==========
	memset
========================*/
# include <string.h>

/*====stdio.h==========
	printf
========================*/
# include <stdio.h>

/*====stdlib.h==========
	malloc, free
========================*/
# include <stdlib.h>

/*====unistd.h==========
	write, usleep
========================*/
# include <unistd.h>

/*====sys/time.h========
	gettimeofday
========================*/
# include <sys/time.h>

/*====pthread.h=========
	pthread_create, pthread_detach, pthread_join,
	pthread_mutex_init, pthread_mutex_destroy,
	pthread_mutex_lock, pthread_mutex_unlock
========================*/
# include <pthread.h>

# include "arguments.h"
# include "philosopher.h"

typedef struct s_table
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	printing;
	pthread_mutex_t	dying;
	int				died;
	t_philosopher	*philos;
	t_arguments		arg;
	long long		start_time;
}	t_table;

/* simulate */
int				simulate(\
						t_table *table, t_arguments arg, t_philosopher *philos);
void			wrap_sleep(long long sleep_time, t_philosopher *philo);
void			*action_philo(void *args);
int				action_eat(t_philosopher *philo);
int				action_sleep(t_philosopher *philo);
int				action_think(t_philosopher *philo);
void			watch_simulate(t_table *table, t_philosopher *philos);

/* mutex */
int				create_mutex(t_table *main, int size);
int				delete_forks(pthread_mutex_t *forks, int size);

/* philos */
t_philosopher	*create_philos(\
	t_table *table, pthread_mutex_t *forks, t_arguments arg);

/* time */
int				get_msec(long long *time);

/* parse */
int				parse_arg(int argc, char *argv[], t_arguments *arg);
int				wrap_atoi(const char *nptr, int *num);

/* validate */
int				validate_arg(int argc, t_arguments *arg);

/* error */
void			putstr_stderr(char *str);
void			error_out(char *str);

#endif /* PHILOSOPHERS_H */
