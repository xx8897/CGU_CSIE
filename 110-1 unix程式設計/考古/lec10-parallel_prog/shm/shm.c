/*******************************************************************************
 *
 * the shared memory demo program
 *
 ******************************************************************************/

#include <semaphore.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct shspace_s {
	int flag;
	int value;
} shspace_t;

shspace_t *shspace;

void
receiver ()
{
	while (shspace->flag==0);
	printf ("Receiver: value = %d\n", shspace->value);
	exit (0);
}//receiver ()

void
sender ()
{
	printf ("Sender: prepare to send value 100\n");
	shspace->value = 100;
	shspace->flag = 1;
	exit (0);
}//sender()

main ()
{
	int shm_mode;
	int shm_id;
	pid_t pid;

	//allocate shared memory
	shm_mode = IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR;
	shm_id = shmget (IPC_PRIVATE, sizeof(shspace_t), shm_mode);
	shspace = (shspace_t*) shmat (shm_id, NULL, SHM_RND);

	//initialize the shared memory
	shspace->value = 0;
	shspace->flag = 0;

	//fork the receiver
	pid = fork ();
	if (pid==0) receiver ();

	//fork the sender
	pid = fork ();
	if (pid==0) sender();

	return 0;
}//main()
















