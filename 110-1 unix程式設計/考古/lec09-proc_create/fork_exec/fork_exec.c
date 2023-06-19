/*******************************************************************************
 *
 * fork a new process and re-direct standard out to a file
 *
 ******************************************************************************/

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include <stdio.h>

main()
{
	int pid;
	int i;
	int status;

	pid = fork ();
	if (pid==0) {	//in child process
		execl ("./hello", NULL);
		fprintf (stderr, "Something wrong if you see this line\n");
	}
	else {	//in parent process
		wait (&status);
		printf ("Parent: the child terminates\n");
	}

	return 0;
}//main()
















