#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>

main()
{
	int fd;
	char buf[] = "abcdefghijklmnopqrstuvwxyz";

	fd = open ("test.fifo", O_RDONLY);
	read (fd, buf, 100);

	printf ("read string from FIFO: %s\n", buf);

	return 0;
}//main()


















