CFLAGS = -g -Wall
CC = g++

all: main

main: main.o DoubleLinkedList.o
	$(CC) $(CFLAGS) main.o DoubleLinkedList.o -o main

main.o : main.cpp
	$(CC) -c main.cpp

DoubleLinkedList.o : DoubleLinkedList.cpp DoubleLinkedList.h
	$(CC) -c DoubleLinkedList.cpp

clean:
	-rm -f core *.o
	-rm -f *.class
	-rm -f main
