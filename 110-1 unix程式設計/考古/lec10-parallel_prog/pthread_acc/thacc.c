#include <pthread.h>
#include <stdio.h>

//the shared address space
int acc;
int count;
pthread_mutex_t mylock;

void *
child_thread (p)
	void *p;
{
	int *key;

	key = (int*) p;

	printf ("Child thread: to accumulate %d\n", *key);

	//the critical section with mutual-exclusive synchronization
	pthread_mutex_lock (&mylock);
	{
		acc = acc + (*key);
		count = count+1;
	}
	pthread_mutex_unlock (&mylock);
}//child_thread

main ()
{
	int i;
	int A[] = {100, 50, 200, 70};
	pthread_t thread_id[4];

	//initialize shared data
	acc = 0;
	count = 0;

	//initialize locks
	pthread_mutex_init (&mylock, NULL);

	//fork child threads
	for (i=0;i<4;i++)
		pthread_create (&(thread_id[i]), NULL, child_thread, &(A[i]));

	while (count<4);
	printf ("Parent: accumulated acc = %d\n", acc);

	return 0;
}//main ()



















