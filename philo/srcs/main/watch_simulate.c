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

static void	print_died(\
	int number, long long now, pthread_mutex_t *printing, int *died)
{
	if ((*died) == 1)
	{
		pthread_mutex_unlock(printing);
		return ;
	}
	printf("%lld %d died\n", now, number);
	(*died) = 1;
}

static int	check_died(int size, t_table *table, t_philosopher *philos)
{
	int			i;
	int			died;
	long long	now;
	long long	last_eat_time;

	i = 0;
	died = 0;
	now = 0;
	while (i < size && died != 1)
	{
		get_msec(&now);
		pthread_mutex_lock(&table->eating);
		pthread_mutex_lock(&table->printing);
		now = now - table->start_time;
		last_eat_time = philos[i].last_eat_time;
		if (now - last_eat_time > table->arg.time_to_die)
		{
			print_died(philos[i].number, now, &table->printing, &died);
			died = 1;
		}
		pthread_mutex_unlock(&table->printing);
		pthread_mutex_unlock(&table->eating);
		i++;
	}
	return (died);
}

static int	check_finish(int size, t_table *table, t_philosopher *philos)
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
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&table->eating);
	return (1);
}

void	watch_simulate(t_table *table, t_philosopher *philos)
{
	int			size;
	long long	now;

	size = table->arg.number_of_philosophers;
	while (table->died != 1)
	{
		table->died = check_died(size, table, philos);
		if (table->died == 1)
			break ;
		if (table->arg.number_of_times_each_philosopher_must_eat != 0)
			table->died = check_finish(size, table, philos);
		if (table->died == 1)
			break ;
		usleep(100);
	}
}
