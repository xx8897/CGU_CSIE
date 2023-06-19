#include <stdio.h>
#include <stdlib.h>

void
bye ()
{
	printf ("Bye bye!!!\n");
}//state_backup

main ()
{
	FILE *fp;
	char str[100];
	int a[5];
	int sum;
	int i;

	atexit (bye);

	for (i=0;i<5;i++) {
		printf ("Input number %d: ", i);
		scanf ("%s", str);
		a[i] = atoi (str);
	}

	sum = 0;
	for (i=0;i<5;i++) sum += a[i];
	printf ("Toal: %d\n", sum);

	return 0;
}//main ()



















