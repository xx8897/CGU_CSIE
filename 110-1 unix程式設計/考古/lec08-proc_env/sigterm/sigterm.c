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

#define MAX_SIGNALS		30

void
exit_handler ()
{
	FILE *fp;

	fp = fopen ("autosave.out", "w");
	fprintf (fp, "I will survive!\n");
	fclose (fp);
}//exit_handler

main()
{
	int i;

	//setup exit and signal handler
	atexit (exit_handler);

	for (i=0;i<MAX_SIGNALS;i++)
		signal (i, exit);


	//wait for file change
	while (1) pause ();
}//main()


















