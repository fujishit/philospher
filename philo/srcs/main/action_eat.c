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

static void	print_taken_fork(\
	int died, int number, long long start_time, pthread_mutex_t *printing)
{
	long long	now;

	get_msec(&now);
	pthread_mutex_lock(printing);
	if (died != 1)
		printf("%lld %d has taken a fork\n", (now - start_time), number);
	pthread_mutex_unlock(printing);
}

static void	print_eating(\
	int died, int number, long long start_time, pthread_mutex_t *printing)
{
	long long	now;

	get_msec(&now);
	pthread_mutex_lock(printing);
	if (died != 1)
		printf("%lld %d is eating\n", (now - start_time), number);
	pthread_mutex_unlock(printing);
}

static void	set_last_eat_time(\
	int died, long long *time, long long start_time, pthread_mutex_t *printing)
{
	long long	now;

	pthread_mutex_lock(printing);
	if (died == 1)
	{
		pthread_mutex_unlock(printing);
		return ;
	}
	get_msec(&now);
	*time = now - start_time;
	pthread_mutex_unlock(printing);
}

void	action_eat(t_philosopher *philo)
{
	pthread_mutex_lock(philo->mutex.left);
	pthread_mutex_lock(philo->mutex.right);
	if (philo->table->died == 1)
	{
		pthread_mutex_unlock(philo->mutex.left);
		pthread_mutex_unlock(philo->mutex.right);
		return ;
	}
	print_taken_fork(philo->table->died, philo->number, philo->table->start_time, philo->mutex.printing);
	pthread_mutex_lock(philo->mutex.eating);
	if (philo->table->died == 1)
	{
		pthread_mutex_unlock(philo->mutex.left);
		pthread_mutex_unlock(philo->mutex.right);
		pthread_mutex_unlock(philo->mutex.eating);
		return ;
	}
	print_eating(philo->table->died, philo->number, philo->table->start_time,
	philo->mutex.printing);
	pthread_mutex_unlock(philo->mutex.eating);
	usleep(philo->arg.time_to_eat * 1000);
	philo->eat_count++;
	set_last_eat_time(philo->table->died, &philo->last_eat_time, philo->table->start_time, philo->mutex.printing);
	pthread_mutex_unlock(philo->mutex.left);
	pthread_mutex_unlock(philo->mutex.right);
	return ;
}
