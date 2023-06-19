#include <pthread.h>
#include <stdio.h>

int flag;
int value;

void *
producer (p)
	void *p;	//not used
{
	value = 100;
	printf ("Producer: the value %d sent\n", value);
	flag = 1;
	while (1);
}//main ()

void *
consumer (p)
	void *p;
{
	while (flag==0);
	printf ("Consumer: get value %d\n", value);
	while (1);
}

main ()
{
	pthread_t producer_id;
	pthread_t consumer_id;
	int i;
	void *p;

	flag = 0;
	value = 0;

	pthread_create (&producer_id, NULL, producer, NULL);
	pthread_create (&consumer_id, NULL, consumer, NULL);

	pthread_join (producer_id, &p);
	printf ("Parent: the producer thread terminates\n");

	pthread_join (consumer_id, &p);
	printf ("Parent: the consumer thread terminates\n");

	return 0;
}//main ()



















