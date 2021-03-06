/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:20:50 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/24 15:20:50 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_pthread_mutex_init(void)
{
	putstr_stderr("init_forks: pthread_mutex_init failure");
	return (1);
}

static pthread_mutex_t	*malloc_forks(int size)
{
	pthread_mutex_t	*forks;

	forks = NULL;
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (size_t)size);
	if (forks == NULL)
	{
		putstr_stderr("malloc_forks: malloc failure");
		return (NULL);
	}
	return (forks);
}

static int	init_forks(pthread_mutex_t *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			delete_forks(forks, i);
			return (error_pthread_mutex_init());
		}
		i++;
	}
	return (0);
}

static int	init_other_mutex(t_table *table, pthread_mutex_t *forks, int size)
{
	if (pthread_mutex_init(&table->eating, NULL))
	{
		delete_forks(forks, size);
		return (error_pthread_mutex_init());
	}
	if (pthread_mutex_init(&table->printing, NULL))
	{
		delete_forks(forks, size);
		pthread_mutex_destroy(&table->eating);
		return (error_pthread_mutex_init());
	}
	if (pthread_mutex_init(&table->dying, NULL))
	{
		delete_forks(forks, size);
		pthread_mutex_destroy(&table->eating);
		pthread_mutex_destroy(&table->printing);
		return (error_pthread_mutex_init());
	}
	return (0);
}

/*malloc and initialize fork, died*/
int	create_mutex(t_table *table, int size)
{
	pthread_mutex_t	*forks;

	forks = malloc_forks(size);
	if (forks == NULL)
		return (1);
	if (init_forks(forks, size) != 0)
	{
		free(forks);
		return (1);
	}
	if (init_other_mutex(table, forks, size) != 0)
	{
		return (1);
	}
	table->forks = forks;
	return (0);
}
