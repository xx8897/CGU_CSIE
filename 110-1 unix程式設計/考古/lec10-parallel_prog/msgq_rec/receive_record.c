#include "./personal_record.h"

#include <stdio.h>

#include<sys/msg.h>

main()
{
	int fd;
	int i;
	msgbuf_t buf;
	int notfinish;
	int msgq_id;

	printf ("The message queue ID: ");
	scanf ("%d", &msgq_id);
	msgrcv (msgq_id, &buf, sizeof(msgbuf_t) - sizeof(long), 0, 0);

	while (buf.notfinish) {
		printf ("============ record ===========\n");
		printf ("Name: %s\n", buf.prec.name);
		printf ("ID: %s\n", buf.prec.ID);
		printf ("deposit: %d\n", buf.prec.deposit);
		printf ("\n");

		msgrcv (msgq_id, &buf, sizeof(msgbuf_t) - sizeof(long), 0, 0);
	}

	return 0;
}//main()


















