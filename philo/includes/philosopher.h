/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:17:07 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 17:17:07 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <pthread.h>

# include "arguments.h"

typedef struct s_table	t_table;

typedef struct s_philo_mutex
{
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	*eating;
	pthread_mutex_t	*dying;
	pthread_mutex_t	*printing;
}	t_philo_mutex;

typedef struct s_philosopher
{
	int				number;
	int				eat_count;
	pthread_t		thread;
	t_arguments		arg;
	t_philo_mutex	mutex;
	t_table			*table;
	long long		last_eat_time;
}	t_philosopher;

t_philosopher	new_philosopher(void);
int				delete_philosopher(t_philosopher *philos);

#endif /* PHILOSOPHER_H */
