/*******************************************************************************
 *
 * to demonstrate the use of semaphore
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

#define num_proc 4

typedef struct shspace_s {
	int		acc;
	int		count;
	sem_t	lock;
} shspace_t;

shspace_t *shspace;

void
child (my_id, my_acc)
	int my_id;
	int my_acc;
{
	printf ("Child %d: accumulating %d\n", my_id, my_acc);

	sem_wait (&(shspace->lock));	//begin of the critical section
	{
		shspace->acc += my_acc;
		shspace->count++;
	}
	sem_post (&(shspace->lock));	//end of the critical section

	exit (0);	//end the child process
}//child ()

main ()
{
	int A[] = {100, 50, 200, 70};
	pid_t pid;
	int shm_mode;
	int shm_id;
	int i;

	//allocate shared memory
	shm_mode = IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR;
	shm_id = shmget (IPC_PRIVATE, sizeof(shspace_t), shm_mode);
	shspace = (shspace_t*) shmat (shm_id, NULL, SHM_RND);

	//initialize shared memory
	shspace->acc = 0;
	shspace->count = 0;
	sem_init (&(shspace->lock), 1, 1);	//initialize semaphore

	//fork child processes
	for (i=0;i<num_proc;i++) {
		pid = fork ();
		if (pid==0) child (i, A[i]);
	}//fork child processes

	//wait for all child finished
	while (shspace->count<num_proc);
	printf ("Total acc=%d\n", shspace->acc);

	return 0;
}//main()



















