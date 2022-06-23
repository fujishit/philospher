/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfujishi <mfujishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 08:30:15 by mfujishi          #+#    #+#             */
/*   Updated: 2022/06/05 08:30:15 by mfujishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*====string.h==========
	memset
========================*/
# include <string.h>

/*====stdio.h==========
	printf
========================*/
# include <stdio.h>

/*====stdlib.h==========
	malloc, free
========================*/
# include <stdlib.h>

/*====unistd.h==========
	write, usleep
========================*/
# include <unistd.h>

/*====sys/time.h========
	gettimeofday
========================*/
# include <sys/time.h>

/*====pthread.h=========
	pthread_create, pthread_detach, pthread_join,
	pthread_mutex_init, pthread_mutex_destroy,
	pthread_mutex_lock, pthread_mutex_unlock
========================*/
# include <pthread.h>

# include "arguments.h"

/* parse */
int	parse_arg(int argc, char *argv[], t_arguments *arg);
int	wrap_atoi(const char *nptr, int *num);

#endif /* PHILOSOPHERS_H */
