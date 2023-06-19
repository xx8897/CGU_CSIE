TARGET = fork_fifo

C_SOURCE_FILES = $(wildcard *.c)
OBJFILES += $(C_SOURCE_FILES:.c=.o)

all: $(TARGET)

clean:
	rm -f *.o
	rm -f *.fifo
	rm -f $(TARGET)

$(TARGET): $(OBJFILES)
	gcc -g -o $@ $^

%.o: %.c
	gcc -g -c $^


















