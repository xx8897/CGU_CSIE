TARGET = fork_redirect hello

CCFLAGS = -DREDIRECT

all: $(TARGET)

clean:
	rm -f $(TARGET)
	rm -f output_file.txt

%: %.c
	gcc $(CCFLAGS) -o $@ $^


















