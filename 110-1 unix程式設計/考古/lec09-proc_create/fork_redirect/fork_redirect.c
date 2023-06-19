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

main(argc, argv)
	int argc;
	char *argv[];
{
	char *prog_arg[100];
	int pid;
	int i;
	int status;
	int param;
	int fd;
	int mode;

	//prepare program argument for the child process
	for (i=0;i<argc-1;i++)
		prog_arg[i] = argv[i+1];
	prog_arg[i] = NULL;

	pid = fork ();
	if (pid==0) {	//in child process
#ifdef REDIRECT
		mode = S_IRUSR | S_IWUSR;
		fd = open ("output_file.txt", O_WRONLY|O_CREAT|O_TRUNC, mode);
		dup2 (fd, STDOUT_FILENO);
#endif
		execv (argv[1], prog_arg);
		fprintf (stderr, "Something wrong if you see this line\n");
	}
	else {	//in parent process
		if (pid<0) {
			printf ("fork error\n");
			return -1;
		}
		wait (&status);
	}

	return 0;
}//main()
















