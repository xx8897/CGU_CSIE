C_SRC_FILES = $(wildcard *.c)
TARGETS = $(C_SRC_FILES:.c=)
GCC_FLAGS +=

all: $(TARGETS)

run: all
	mkfifo rec.fifo
	xterm -e ./receive_record &
	sleep 5
	xterm -e ./send_record &

clean:
	rm -f *.o
	rm -f $(TARGETS)
	rm -f *.fifo

%: personal_record.h %.c
	gcc $(GCC_FLAGS) -o $@ $(filter %.c, $^)


















