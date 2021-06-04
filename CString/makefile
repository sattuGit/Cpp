CC=gcc
CCFLAG=-std=c99
CCFLAG += -g
all: main
main: main.o strFun.o interviewtask.o
	$(CC) $(CCFLAG) -o CString interviewtask.o strFun.o main.o
main.o: main.c
	$(CC) -c main.c
strFun.o: strFun.c strFun.h
	$(CC) -c strFun.c strFun.h
interviewtask.o: interviewtask.c interviewtask.h
	$(CC) -c interviewtask.c interviewtask.h

.PHONY: clean
clean:
	rm -f *.o *.gch CString
