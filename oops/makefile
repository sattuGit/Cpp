CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: oops
oops: access.o constructure.o main.o friend.o  inheritance.o testInheritance.o 
	$(CC) -o oops  $(FLAG) inheritance.o testInheritance.o friend.o access.o constructure.o oopsMain.o
main.o: oopsMain.o
	$(CC) -c oopsMain.cpp 
const.o: constructure.hpp constructure.cpp
	$(CC) -c constructure.hpp constructure.cpp
access.o: access.h access.cpp
	$(CC) -c access.h access.cpp 
friend.o: friend.h friend.cpp 
	$(CC) -c friend.h friend.cpp
inheritance.o: inheritance.h inheritance.cpp testInheritance.h testInheritance.cpp
	$(CC) -c inheritance.h inheritance.cpp testInheritance.h testInheritance.cpp
.PHONY: clean
clean:
	rm -f oops *.o *.gch