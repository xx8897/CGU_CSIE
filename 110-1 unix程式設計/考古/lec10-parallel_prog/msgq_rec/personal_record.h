
#ifndef PERSONAL_RECORD_H

#define PERSONAL_RECORD_H

typedef struct personal_record_s {
	char	name[30];
	char	ID[10];
	int		deposit;
} personal_record_t;

typedef struct msgbuf_s {
	long				mtype;
	int					notfinish;
	personal_record_t	prec;
} msgbuf_t;

#endif
