/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 21:28:26 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 21:28:26 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	print_taken_fork(t_philosopher *philo, t_table *table)
{
	long long	now;
	long long	start_time;

	get_msec(&now);
	start_time = table->start_time;
	pthread_mutex_lock(&table->dying);
	if (table->died == 1)
	{
		pthread_mutex_unlock(&table->dying);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&table->dying);
		pthread_mutex_lock(&table->printing);
		printf("%lld %d has taken a fork\n", (now - start_time), philo->number);
		pthread_mutex_unlock(&table->printing);
		return (0);
	}
}

static int	print_eating(t_philosopher *philo, t_table *table)
{
	long long	now;
	long long	start_time;

	get_msec(&now);
	start_time = table->start_time;
	pthread_mutex_lock(&table->dying);
	if (table->died == 1)
	{
		pthread_mutex_unlock(&table->dying);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&table->dying);
		pthread_mutex_lock(&table->printing);
		printf("%lld %d is eating\n", (now - start_time), philo->number);
		pthread_mutex_unlock(&table->printing);
		return (0);
	}
}

static int	set_last_eat_time(t_philosopher *philo, t_table *table)
{
	long long	now;
	long long	start_time;

	pthread_mutex_lock(&table->dying);
	start_time = table->start_time;
	if (table->died == 1)
	{
		pthread_mutex_unlock(&table->dying);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&table->dying);
		get_msec(&now);
		philo->last_eat_time = now - start_time;
		return (0);
	}
}

int	action_eat(t_philosopher *philo)
{
	// printf("lock       left[%p], right[%p]\n", philo->mutex.left, philo->mutex.right);
	printf("[%d]番目の哲学者がフォークをほしがってるよ\n", philo->number);
	pthread_mutex_lock(philo->mutex.left);
	pthread_mutex_lock(philo->mutex.right);
	printf("[%d]番目の哲学者がフォークをとったよ\n", philo->number);
	if (print_taken_fork(philo, philo->table) == 1)
	{
		pthread_mutex_unlock(philo->mutex.left);
		pthread_mutex_unlock(philo->mutex.right);
		return (1);
	}
	pthread_mutex_lock(philo->mutex.eating);
	if (print_eating(philo, philo->table) == 1)
	{
		pthread_mutex_unlock(philo->mutex.eating);
		pthread_mutex_unlock(philo->mutex.left);
		pthread_mutex_unlock(philo->mutex.right);
		return (1);
	}
	pthread_mutex_unlock(philo->mutex.eating);
	if (set_last_eat_time(philo, philo->table) == 1)
	{
		pthread_mutex_unlock(philo->mutex.eating);
		pthread_mutex_unlock(philo->mutex.left);
		pthread_mutex_unlock(philo->mutex.right);
		return (1);
	}
	philo->eat_count++;
	printf("[%d]番目の哲学者が食事をしてるよ\n", philo->number);
	wrap_sleep(philo->arg.time_to_eat);
	pthread_mutex_unlock(philo->mutex.left);
	pthread_mutex_unlock(philo->mutex.right);
	printf("[%d]番目の哲学者がフォークを置いたよ\n", philo->number);

	return (0);
}
