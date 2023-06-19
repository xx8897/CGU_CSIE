#include "./personal_record.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

personal_record data_set[] = {
	{"Pink",	"Q12344488", 1970, 5, 30, 20000},
	{"Floyd",	"A12340099", 1987, 3, 20, 12000},
	{"King",	"B98765432", 1991, 12,25, 30000},
	{"Crimson",	"C09876543", 2002, 10,11, 40000}
};

main()
{
	int fd;
	int i;

	fd = open ("data.bin", O_WRONLY);
	for (i=0;i<4;i++) {
		write (fd, &(data_set[i]), sizeof(personal_record));
	}

	return 0;
}//main()


















