################################################################################
#
# to build the demo program of the linked list
#
################################################################################

CC = gcc
CFLAGS += -I. -g

TARGETS = list_demo

HEADER_FILES = $(wildcard *.h)
C_SOURCE_FILES = $(wildcard *.c)
OBJ_FILES = $(C_SOURCE_FILES:.c=.o)

all: $(TARGETS)

clean:
	rm -f *.o
	rm -f *.gch
	rm -f $(TARGETS)

list_demo: $(OBJ_FILES)
	$(CC) -o $@ $^

%.o: $(HEADER_FILES) %.c
	$(CC) -c $(CFLAGS) $^



















