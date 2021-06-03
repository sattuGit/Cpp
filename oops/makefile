CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: oops
oops: access.o constructure.o main.o friend.o  inheritance.o testInheritance.o
	$(CC) -o oops  $(FLAG) inheritance.o friend.o access.o constructure.o oopsMain.o  testInheritance.o
main.o: oopsMain.o
	$(CC) -c oopsMain.cpp 
const.o: constructure.hpp constructure.cpp
	$(CC) -c constructure.hpp constructure.cpp
access.o: access.h access.cpp
	$(CC) -c access.h access.cpp 
friend.o: friend.h friend.cpp 
	$(CC) -c friend.h friend.cpp
testInheritance.o: testInheritance.h testInheritance.cpp inheritance.o
	$(CC) -c testInheritance.h testInheritance.cpp
inheritance.o: inheritance.h inheritance.cpp
	$(CC) -c inheritance.h inheritance.cpp
.PHONY: clean
clean:
	rm -f oops *.o *.gch