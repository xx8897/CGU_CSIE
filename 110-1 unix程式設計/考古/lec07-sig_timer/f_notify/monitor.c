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
fnotify_handler (arg)
	int arg;
{
	printf ("file modified %d\n", ++cnt);
}//fnotify_handler ()

main()
{
	int fd;

	//setup signal handler
	cnt = 0;
	signal (SIGIO, fnotify_handler);

	//open the file
	fd = open (".", O_RDONLY);
	fcntl (fd, F_NOTIFY, DN_MODIFY|DN_MULTISHOT);

	//wait for file change
	while (1) pause ();
}//main()


















