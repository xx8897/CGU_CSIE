TARGETS = sender.exe receiver.exe

all: $(TARGETS)

run: all
	mkfifo test.fifo
	xterm -e ./sender.exe &
	sleep 5
	./receiver.exe

run2: all
	mkfifo test.fifo
	./receiver.exe &
	sleep 5
	xterm -e ./sender.exe &

clean:
	rm -f *.exe
	rm -f *.fifo

%.exe: %.c
	gcc -o $@ $^


















