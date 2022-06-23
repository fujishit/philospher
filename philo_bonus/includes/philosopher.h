#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

/*====string.h==========
	memset,
========================*/
# include <string.h>

/*====stdio.h==========
	printf,
========================*/
# include <stdio.h>

/*====stdlib.h==========
	malloc, free, exit
========================*/
# include <stdlib.h>

/*====unistd.h==========
	write, fork, usleep
========================*/
# include <unistd.h>

/*====signal.h==========
	kill
========================*/
# include <signal.h>

/*====pthread.h=========
	pthread_create, pthread_detach, pthread_join
========================*/
# include <pthread.h>

/*====sys/time.h========
	gettimeofday
========================*/
# include <sys/time.h>

/*====sys/wait.h========
	waitpid
========================*/
# include <sys/wait.h>

/*====semaphore.h=======
	sem_open,  sem_close, sem_post, sem_wait, sem_unlink
========================*/
#include <semaphore.h>

#endif /* PHILOSOPHER_H */
