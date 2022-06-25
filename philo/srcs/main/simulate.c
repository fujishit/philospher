/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:08:45 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 18:08:45 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_get_msec(void)
{
	putstr_stderr("simulate: gettimeofday error");
	return (1);
}

static int	error_pthread_create(void)
{
	putstr_stderr("simulate: pthread_create error");
	return (1);
}

static int	detach_all(t_philosopher *philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_detach(philos[i].thread);
		i++;
	}
	return (0);
}

static int	join_all(t_philosopher *philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	return (0);
}

int	simulate(t_table *table, t_arguments arg, t_philosopher *philos)
{
	int	i;

	i = 0;
	if (get_msec(&table->start_time) != 0)
		return (error_get_msec());
	table->died = 0;
	while (i < arg.number_of_philosophers)
	{
		philos[i].last_eat_time = table->start_time;
		if (pthread_create(\
			&philos[i].thread, NULL, action_philo, &philos[i]) != 0)
		{
			detach_all(philos, arg.number_of_philosophers);
			return (error_pthread_create());
		}
		i++;
	}
	watch_simulate(table, philos);
	join_all(philos, arg.number_of_philosophers);
	return (0);
}
