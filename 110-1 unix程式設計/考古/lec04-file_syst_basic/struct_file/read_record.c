#include "./personal_record.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
	int fd;
	int i;
	personal_record buf;

	fd = open ("data.bin", O_RDONLY);
	for (i=0;i<4;i++) {
		read (fd, &buf, sizeof(personal_record));

		printf ("============ record %d ===========\n", i);
		printf ("Name: %s\n", buf.name);
		printf ("ID: %s\n", buf.ID);
		printf ("birth day %d/%d/%d\n", buf.birth_year, buf.birth_month,
			buf.birth_day);
		printf ("deposit: %d\n", buf.deposit);
	}

	return 0;
}//main()


















