main: main.o copy.o
	gcc –o main main.o copy.o
main.o: main.c copy.h
	gcc main.o -c main.c copy.h
copy.o: copy.c
	gcc copy.c

