/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:30:23 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 08:30:23 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	delete_forks(pthread_mutex_t *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	return (0);
}

static int	delete_structs(t_table *table, t_philosopher *philos, int size)
{
	delete_forks(table->forks, size);
	delete_philosopher(philos);
	pthread_mutex_destroy(&table->printing);
	pthread_mutex_destroy(&table->eating);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table			table;
	t_arguments		arg;
	t_philosopher	*philos;

	arg = new_arg();
	if (parse_arg(argc, argv, &arg) != 0)
		return (1);
	show_arg(arg);
	if (validate_arg(argc, &arg) != 0)
		return (1);
	table.arg = arg;
	table.philos = philos;
	if (create_mutex(&table, philos, arg.number_of_philosophers) != 0)
		return (1);
	philos = create_philos(&table, table.forks, arg);
	if (philos == NULL)
		return (!delete_forks(table.forks, arg.number_of_philosophers));
	if (simulate(&table, arg, philos) == 1)
		return (!delete_structs(&table, philos, arg.number_of_philosophers));
	return (delete_structs(&table, philos, arg.number_of_philosophers));
}
