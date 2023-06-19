################################################################################
#
# A multi-file make example
#
################################################################################

mainprog: foo.o haha.o main.o
	gcc foo.o haha.o main.o -o mainprog

clean:
	rm -f *.o
	rm -f mainprog

foo.o: foo.c
	gcc -c -O2 foo.c

haha.o: haha.c
	gcc -c -O2 haha.c

main.o: main.c
	gcc -c -O2 main.c


















