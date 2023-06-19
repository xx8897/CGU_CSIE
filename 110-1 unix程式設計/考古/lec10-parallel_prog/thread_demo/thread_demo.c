#include <pthread.h>
#include <stdio.h>

void *
thread_01 (p)
	void *p;	//not used
{
	int i;

	printf ("Thread 01: mile-stone 1\n");
	for (i=0;i<100000;i++);	//wait for some times

	printf ("Thread 01: mile-stone 2\n");
	for (i=0;i<300;i++);	//wait for some times

	printf ("Thread 01: mile-stone 3\n");
}//thread_01 ()

void *
thread_02 (p)
	void *p;	//not used
{
	int i;

	for (i=0;i<100;i++);

	printf ("Thread 02: mile-stone 1\n");
	for (i=0;i<1000;i++);	//wait for some times

	printf ("Thread 02: mile-stone 2\n");
	for (i=0;i<50000;i++);	//wait for some times

	printf ("Thread 02: mile-stone 3\n");
}//thread_02 ()

main ()
{
	pthread_t th01, th02;
	int i;
	void *p;

	pthread_create (&th01, NULL, thread_01, NULL);
	pthread_create (&th02, NULL, thread_02, NULL);

	pthread_join (th01, &p);
	pthread_join (th02, &p);

	return 0;
}//main ()



















