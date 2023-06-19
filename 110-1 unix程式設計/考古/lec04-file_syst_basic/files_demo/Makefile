C_SRC_FILES += $(wildcard *.c)
TARGETS = $(C_SRC_FILES:.c=)
GCC_FLAGS +=

all: $(TARGETS)

clean:
	rm -f *.o
	rm -f $(TARGETS)
	rm -f *.txt
	rm -f *.bin

%: %.c
	gcc -o $@ $(GCC_FLAGS) $^




















