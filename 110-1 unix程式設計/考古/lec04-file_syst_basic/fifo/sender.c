#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>

#include <stdio.h>

main()
{
	int fd;


	printf ("sending string Hello!\n");

	fd = open ("test.fifo", O_WRONLY);
	write (fd, "Hello!", strlen("Hello!")+1);

	printf ("DONE! press CTRL-C to exit\n");
	while (1);

	return 0;
}//main()


















