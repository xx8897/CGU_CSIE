all: write_record read_record

run: all
	touch data.bin
	./write_record
	./read_record

clean:
	rm -f write_record read_record data.bin

write_record: personal_record.h write_record.c
	gcc -o $@ write_record.c

read_record: personal_record.h read_record.c
	gcc -o $@ read_record.c


















