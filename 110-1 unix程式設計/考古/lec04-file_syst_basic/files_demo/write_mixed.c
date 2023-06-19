#include <stdio.h>

main (argc, argv)
	int argc;
	char *argv[];
{
	int a[] = {0x12345678, 0xabcdef00, 0x98765432, 0xaabbccdd, 0x11223344};
	FILE *fp;

	fp = fopen (argv[1], "w");
	fwrite (a, 5, sizeof(int), fp);
	fprintf (fp, "hello");
	fclose (fp);

	return 0;
}//main



















