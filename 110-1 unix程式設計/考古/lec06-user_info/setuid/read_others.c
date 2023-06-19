/*******************************************************************************
 *
 * to read other user's file
 *
 ******************************************************************************/

#include <stdio.h>

main(argc, argv)
	int argc;
	char *argv[];
{
	FILE *fp;
	char c;

	fp = fopen (argv[1], "r");
	while ((c=fgetc(fp))!=EOF)
		printf ("%c", c);

	return 0;
}//main()

















