################################################################################
#
# to build and install
#
#
################################################################################

TARGET = read_others

all: $(TARGET)

install: $(TARGET)
	cp $^ /tmp
	chmod 04755 /tmp/read_others

$(TARGET): read_others.c
	gcc -o $@ $^

clean:
	rm -f $(TARGET)

















