TARGET = myshell

all: $(TARGET)

$(TARGET): myshell.c
	gcc -o $@ $^ -lreadline

clean:
	rm -f $(TARGET)

install: $(TARGET)
	cp $(TARGET) /tmp










