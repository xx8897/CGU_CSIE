#include <stdio.h>

main (argc, argv)
	int argc;
	char *argv[];
{
	FILE *fp;
	int a[] = {0x12345678, 0xabcdef00, 0x98765432, 0xaabbccdd, 0x11223344};

	fp = fopen (argv[1], "w");
	fwrite (a, sizeof(int), 5, fp);
	fclose (fp);

	return 0;
}//main ()



















