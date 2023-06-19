#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int flag;

void
sig_handler (arg)
	int arg;
{
	flag = 0;

	return;
}//sig_handler

main ()
{
	pid_t pid;
	int fd;
	int status;

	flag = 1;
	signal (SIGCONT, sig_handler);

	pid = fork ();
	if (pid==0) {	//the child process
		while (flag);	//busy waiting
		receiver ();
	}
	else {	//the parent process
		mkfifo ("test.fifo", S_IWUSR | S_IRUSR);
		kill (pid, SIGCONT);
		sender ();
		wait ();
	}

	return 0;
}//main ()


















