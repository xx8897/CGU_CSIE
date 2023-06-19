#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

int
receiver ()
{
	int fd;
	char buf[] = "abcdefghijklmnopqrstuvwxyz";

	fd = open ("test.fifo", O_RDONLY);
	read (fd, buf, 100);

	printf ("\tChild: read string from FIFO: %s\n", buf);

	return 0;
}//main()


















