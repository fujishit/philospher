/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch_simulate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:57:26 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 22:57:26 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	print_died(t_philosopher *philo, t_table *table, long long now)
{
	pthread_mutex_lock(&table->printing);
	printf("%lld %d died\n", now, philo->number);
	pthread_mutex_unlock(&table->printing);
}

static int	check_died(int size, t_table *table, t_philosopher *philos, int *died)
{
	int			i;
	long long	now;
	long long	last_eat_time;

	i = 0;
	now = 0;
	while (i < size && (*died) != 1)
	{
		get_msec(&now);
		now = now - table->start_time;
		pthread_mutex_lock(&table->eating);
		last_eat_time = philos[i].last_eat_time;
		if (now - last_eat_time > table->arg.time_to_die)
		{
			pthread_mutex_unlock(&table->eating);
			print_died(&philos[i], table, now);
			pthread_mutex_lock(&table->dying);
			(*died) = 1;
			pthread_mutex_unlock(&table->dying);
			return (*died);
		}
		else
			pthread_mutex_unlock(&table->eating);
		i++;
	}
	return (*died);
}

static int	check_finish(int size, t_table *table, t_philosopher *philos, int *died)
{
	int	i;
	int	must;

	i = 0;
	must = table->arg.number_of_times_each_philosopher_must_eat;
	pthread_mutex_lock(&table->eating);
	while (i < size)
	{
		if (philos[i].eat_count < must)
		{
			pthread_mutex_unlock(&table->eating);
			return (*died);
		}
		i++;
	}
	pthread_mutex_lock(&table->dying);
	(*died) = 1;
	pthread_mutex_unlock(&table->eating);
	pthread_mutex_unlock(&table->dying);
	return (*died);
}

void	watch_simulate(t_table *table, t_philosopher *philos)
{
	int			size;
	long long	now;

	size = table->arg.number_of_philosophers;
	while (1)
	{
		if (check_died(size, table, philos, &table->died) == 1)
			return ;
		if (table->arg.number_of_times_each_philosopher_must_eat != 0)
			if (check_finish(size, table, philos, &table->died) == 1)
				return ;
		usleep(100);
	}
}
