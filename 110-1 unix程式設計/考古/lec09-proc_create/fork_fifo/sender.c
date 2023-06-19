#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <string.h>

#include <stdio.h>

int
sender ()
{
	int fd;


	printf ("Parent: sending string Hello!\n");

	fd = open ("test.fifo", O_WRONLY);
	write (fd, "Hello!", strlen("Hello!")+1);

	return 0;
}//main()


















