CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: dp
dp: mainDP.o factory.o testDP.o
	$(CC) -o dpattern  $(FLAG) mainDP.o testDP.o
mainDP.o: mainDP.cpp 
	$(CC) -c mainDP.cpp 
testDP.o: testDP.cpp testDP.h 
	$(CC) -c testDP.cpp testDP.h 
factory.o: DPF.h
	$(CC) -c DPF.h
.PHONY: clean
clean:
	rm -f dpattern *.o *.gch