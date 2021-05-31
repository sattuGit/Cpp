CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: oops
oops: access.o constructure.o main.o friend.o
	$(CC) -o oops  $(FLAG) friend.o access.o constructure.o oopsMain.o
main.o: oopsMain.o
	$(CC) -c oopsMain.cpp 
const.o: constructure.hpp constructure.cpp
	$(CC) -c constructure.hpp constructure.cpp
access.o: access.h access.cpp
	$(CC) -c access.h access.cpp 
friend.o: friend.h friend.cpp 
	$(CC) -c friend.h friend.cpp 
.PHONY: clean
clean:
	rm -f oops *.o *.gch 
