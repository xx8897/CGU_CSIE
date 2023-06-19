#include <stdio.h>

main (argc, argv)
	int argc;
	char *argv[];
{
	FILE *fp;
	char str[100];

	fp = fopen (argv[1], "r");
	if (fp==NULL) return -1;
	fscanf (fp, "%s", str);
	printf ("%s\n", str);

	return 0;
}//main ()



















