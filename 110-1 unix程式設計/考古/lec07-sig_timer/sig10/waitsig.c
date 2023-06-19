/*******************************************************************************
 *
 * to monitor a file change
 *
 ******************************************************************************/

#define _GNU_SOURCE

#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <signal.h>

#include <stdio.h>
#include <stdlib.h>

int cnt;

void
sig10_handler (arg)
	int arg;
{
	printf ("I got signal 10: time %d\n", ++cnt);
}//fnotify_handler ()

main()
{
	int fd;

	//setup signal handler
	cnt = 0;
	signal (10, sig10_handler);

	//wait for file change
	while (1) pause ();
}//main()


















