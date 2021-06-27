CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: oops
oops: 
	$(CC)  --version #-o puzzle  $(FLAG) inheritance.o testInheritance.o friend.o access.o constructure.o oopsMain.o
.PHONY: clean
clean:
	rm -f puzzle *.o *.gch
