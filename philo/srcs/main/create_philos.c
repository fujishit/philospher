/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 23:03:21 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/23 23:03:21 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_malloc(void)
{
	error_out("Create_philos: malloc failure");
	return (1);
}

/* malloc t_philosopher */
static t_philosopher	*malloc_philos(int size)
{
	t_philosopher	*philos;

	philos = NULL;
	philos = (t_philosopher *)malloc(sizeof(t_philosopher) * (size_t)size);
	if (philos == NULL)
	{
		error_malloc();
		return (NULL);
	}
	return (philos);
}

static void	have_forks(t_philosopher *philos, pthread_mutex_t *forks, int size)
{
	int	i;

	philos[0].mutex.left = &forks[size - 1];
	philos[0].mutex.right = &forks[0];
	i = 1;
	while (i < size)
	{
		philos[i].mutex.left = &forks[i - 1];
		philos[i].mutex.right = &forks[i];
		i++;
	}
}

/* malloc and initialize t_philosopher */
t_philosopher	*create_philos(\
	t_table *table, pthread_mutex_t *forks, t_arguments arg)
{
	int				i;
	int				size;
	t_philosopher	*philos;

	i = 0;
	size = arg.number_of_philosophers;
	philos = malloc_philos(size);
	if (philos == NULL)
		return (NULL);
	while (i < size)
	{
		philos[i] = new_philosopher();
		philos[i].arg = arg;
		philos[i].table = table;
		philos[i].mutex.eating = &table->eating;
		philos[i].mutex.printing = &table->printing;
		philos[i].mutex.dying = &table->dying;
		philos[i].number = i + 1;
		i++;
	}
	have_forks(philos, forks, size);
	return (philos);
}
