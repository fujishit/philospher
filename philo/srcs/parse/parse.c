/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:43:15 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 11:43:15 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	error_invalid_number(char *argv)
{
	error_out("Parse: Invalid number");
	putstr_stderr(argv);
	putstr_stderr("\n");
	return (1);
}

int	parse_arg(int argc, char *argv[], t_arguments *arg)
{
	if (argc == 5 || argc == 6)
	{
		if (wrap_atoi(argv[1], &arg->number_of_philosophers) == 1)
			return (error_invalid_number(argv[1]));
		else if (wrap_atoi(argv[2], &arg->time_to_die) == 1)
			return (error_invalid_number(argv[2]));
		else if (wrap_atoi(argv[3], &arg->time_to_eat) == 1)
			return (error_invalid_number(argv[3]));
		else if (wrap_atoi(argv[4], &arg->time_to_sleep) == 1)
			return (error_invalid_number(argv[4]));
		else if (argc == 6 && wrap_atoi(\
			argv[5], &arg->number_of_times_each_philosopher_must_eat) == 1)
			return (error_invalid_number(argv[5]));
	}
	else
	{
		error_out("Parse: Invalid args");
		putstr_stderr("  ./philo philo_num die_time eat_time sleep_time\n");
		return (2);
	}
	return (0);
}
