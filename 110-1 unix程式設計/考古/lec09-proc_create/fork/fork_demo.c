#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int x;

main ()
{
	pid_t pid;
	int a;

	a = 10;
	x = 20;

	pid = fork ();
	if (pid==0) {	//in the child process
		printf ("\tChild: a = %d\n", a);
		printf ("\tChild: x = %d\n", x);
		a = 100;
		x = 200;
		printf ("\tChild: a = %d\n", a);
		printf ("\tChild: x = %d\n", x);
		while (1);
	}
	else {	//in the parent process
		printf ("Parent: a = %d\n", a);
		printf ("Parent: x = %d\n", x);
		a = 30;
		x = 400;
		printf ("Parent: a = %d\n", a);
		printf ("Parent: x = %d\n", x);
		while (1);
	}
}//main()




















