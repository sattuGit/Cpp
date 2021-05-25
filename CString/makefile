CC=gcc
CCFLAG=-std=c99
CCFLAG += -g
all: main
main: main.o strFun.o
	$(CC) $(CCFLAG) -o CString strFun.o main.o
main.o: main.c
	$(CC) -c main.c
strFun.o: strFun.c strFun.h
	$(CC) -c strFun.c strFun.h
.PHONY: clean
clean:
	rm *.o *.gch CString
