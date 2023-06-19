#include "./personal_record.h"

#include <stdio.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/msg.h>

main()
{
	int fd;
	int i;
	char c[10];
	int notfinish;
	char garbage;
	int msgq_id;
	int msgq_flag;
	msgbuf_t buf;
	personal_record_t *rec;

	rec = &(buf.prec);

	msgq_flag = IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR;
	msgq_id = msgget (IPC_PRIVATE, msgq_flag);
	printf ("The message queue ID: %d\n", msgq_id);

	notfinish = 1;
	while (notfinish) {
		printf ("Input a new record? (y/n): ");
		scanf ("%s", c);

		if (c[0]=='y' || c[0]=='Y') {	//input a new record
			printf ("Name: ");
			scanf ("%s", &(rec->name));
			printf ("ID number: ");
			scanf ("%s", &(rec->ID));
			printf ("Deposit: ");
			scanf ("%d", &(rec->deposit));
			printf ("\n");

			buf.mtype = 1;
			buf.notfinish = 1;
			msgsnd (msgq_id, &buf, sizeof(msgbuf_t) - sizeof(long), 0);
		}
		else {	//terminate execution
			buf.mtype = 1;
			buf.notfinish = 0;
			msgsnd (msgq_id, &buf, sizeof(msgbuf_t) - sizeof(long), 0);
			notfinish = 0;
		}
	}

	return 0;
}//main()


















