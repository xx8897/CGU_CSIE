#include <stdio.h>

main (argc, argv)
	int argc;
	char *argv[];
{
	unsigned char buf [400];
	int n;
	int i;
	FILE *fp;
	char c;

	fp = fopen (argv[1], "r");
	n = fread (buf, sizeof(char), 400, fp);

	for (i=0;i<n;i++) {
		c = (buf[i]>='a' && buf[i]<='z')? buf[i]: '.';
		printf ("0x%02x\t%c\n", buf[i], c);
	}
	printf ("\n");

	return 0;
}//main ()



















