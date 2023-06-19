/*******************************************************************************
 *
 * my text-mode alarm clock program
 *
 ******************************************************************************/

#include <time.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>

int target_hour, target_min;

void
alarm_handler (arg)
	int arg;
{
	printf ("It's time %d:%d:00\n", target_hour, target_min);
	system ("play /usr/share/sounds/phone.wav");
}//alarm_handler()

main(argc, argv)
	int argc;
	char *argv[];
{
	time_t cur_time;
	struct tm *cur_time_tm;
	int cur_sec, target_sec;
	int wait_sec;

	/* setup the signal handler */
	signal (SIGALRM, alarm_handler);

	/* get alarm time in second (related to 00:00:00 today) */
	sscanf (argv[1], "%d:%d", &target_hour, &target_min);
	target_sec = 3600*target_hour + 60*target_min;

	/* get current time in second (related to 00:00:00 today) */
	time (&cur_time);
	cur_time_tm = localtime (&cur_time);
	cur_sec = cur_time_tm->tm_hour*3600 + cur_time_tm->tm_min*60 +
		cur_time_tm->tm_sec;

	/* setup the alarm signal */
	wait_sec = target_sec - cur_sec;
	if (wait_sec<0) return 0;
	alarm (wait_sec);

	printf ("It's now %d:%d:%d and I'll wake you up at %d:%d:00\n",
		cur_time_tm->tm_hour,
		cur_time_tm->tm_min,
		cur_time_tm->tm_sec,
		target_hour,
		target_min
	);

	pause ();

	return 0;
}//main()

















