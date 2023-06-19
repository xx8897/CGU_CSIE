#include <stdio.h>

main (argc, argv)
	int argc;
	char *argv[];
{
	FILE *fp;
	int buf[100];
	int n;
	int i;

	fp = fopen (argv[1], "r");
	if (fp==NULL) return -1;

	n = fread (buf, sizeof(int), 100, fp);
	for (i=0;i<n;i++)
		printf ("0x%08x ", buf[i]);
	printf ("\n");

	return 0;
}//main ()



















