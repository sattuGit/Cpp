CC=gcc
CCFLAG=-std=c99
CCFLAG += -g
all: log
log: log.h log.c
	$(CC) -c log.c log.h
.PHONY: clean
clean:
	rm -f *.o *.gch
