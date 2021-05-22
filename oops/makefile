CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: oops
oops: constructure.o main.o
	$(CC) -o oops  $(FLAG) constructure.o oopsMain.o
main.o: oopsMain.o
	$(CC) -c oopsMain.cpp 
const.o: constructure.hpp constructure.cpp
	$(CC) -c constructure.hpp constructure.cpp
clean:
	rm -f oops  *.o  *.gch 