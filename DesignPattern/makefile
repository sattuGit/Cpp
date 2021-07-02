CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: dp
dp: main.o factory.o testDP.o
	$(CC) -o dpattern  $(FLAG) MainDP.o testInheritance.o friend.o access.o constructure.o oopsMain.o
main.o: MainDP.o
	$(CC) -c MainDP.cpp 
testDP.o: testDP.o
	$(CC) -c testDP.cpp testDP.h
factory.o: DPF.h
	$(CC) -c DPF.h
.PHONY: clean
clean:
	rm -f dpattern *.o *.gch