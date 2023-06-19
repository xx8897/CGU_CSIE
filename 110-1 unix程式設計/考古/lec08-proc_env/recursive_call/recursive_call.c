#include <stdio.h>

int c;

void
foo (x)
	int x;
{
	int a;
	static int b;

	printf ("======== level %d ===========\n", x);
	printf ("address (a) = 0x%x\n", &a);
	printf ("address (b) = 0x%x\n", &b);
	printf ("address (c) = 0x%x\n", &c);

	if (x==0) return;
	else foo (x-1);
}//foo()

main ()
{
	foo (2);
	return 0;
}



















