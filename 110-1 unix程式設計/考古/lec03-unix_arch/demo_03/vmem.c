#include <stdlib.h>
#include <stdio.h>

//#define SIZE_512M	(512*1024*1024)

main()
{
	long *a;
	long i;
	int c;
	long a_size = 0x80000000;

	printf ("input any integer: ");
	scanf ("%d", &c);

	a = malloc (sizeof(long)*a_size);
	for (i=0;i<a_size;i++)
		a[i] = 0;

	return 0;
}//main()



















