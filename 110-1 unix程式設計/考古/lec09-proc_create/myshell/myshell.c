/*******************************************************************************
 *
 * my simple shell program
 *
 ******************************************************************************/

#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

#include <stdio.h>
#include <string.h>

#include <readline/readline.h>
#include <readline/history.h>

int fd;

void
sigusr1_handler (intno)
	int intno;
{
	//just do nothing and return
	//printf ("intno = %d\n", intno);
}

pid_t
create_fg_proc (exe_path)
	char *exe_path;
{
	pid_t pid;
	int tc_val;

	pid = fork ();
	if (pid==0) {	//in child process
		pause ();	//wait for SIGUSR1 sent from the parent
		execv (exe_path, NULL);
	}
	else {	//in parent process
		setpgid (pid, pid);

		tc_val = tcsetpgrp (fd, pid);	//set as foreground group
		kill (pid, SIGUSR1);	//make chile execute
	}

	return pid;
}//create_fg_proc ()

main()
{
	int not_finish = 1;
	char *cmd_path;
	pid_t pid, my_pid, my_pgid, tcpgid;
	int status;
	int val;
	sigset_t sigmask;

	fd = open ("/dev/tty", O_RDONLY|O_WRONLY);
	my_pid = getpid ();
	my_pgid = getpgid (my_pid);
	tcpgid = tcgetpgrp (fd);
	printf ("my_pid=%d my_pgid=%d tcpgid=%d\n", my_pid, my_pgid, tcpgid);

	//register signal handler for synchronization
	signal (SIGUSR1, sigusr1_handler);

	//block SIGTTOU to re-gain controlling terminal
	sigemptyset (&sigmask);
	sigaddset (&sigmask, SIGTTOU);
	sigprocmask (SIG_BLOCK, &sigmask, NULL);

	while (not_finish) {
		cmd_path = readline ("$>");

		if (!strcmp(cmd_path, "exit")) {
			not_finish = 0;
			break;
		}

		else if (!strcmp(cmd_path, ""))
			continue;

		pid = create_fg_proc (cmd_path);
		waitpid (pid, &status, 0);
		//wait (&status);
		val = tcsetpgrp (fd, my_pgid);
	}

	return 0;
}//main()


















