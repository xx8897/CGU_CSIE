/*******************************************************************************
 *
 * demo program to get the on-line user list
 *
 ******************************************************************************/

#include <utmp.h>
#include <stdio.h>

main()
{
	FILE *fp;
	struct utmp user_rec;

	fp = fopen ("/var/run/utmp", "r");
	while (fread(&user_rec, sizeof(struct utmp), 1, fp)>0)
		printf ("%s\t\t%s\n", user_rec.ut_user, user_rec.ut_line);

	return 0;
}//main()


















