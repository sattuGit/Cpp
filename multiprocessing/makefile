CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= forkSimple childControl execvp forkShared
all: $(TARGET)
forkSimple: SimpleCFork.c
	$(CC) -o forkSimple $(FLAG) SimpleCFork.c
childControl: childControl.c
	$(CC) -o childControl $(FLAG) childControl.c
execvp: execvp.c
	$(CC) -w -o execvp $(FLAG) execvp.c 
forkShared: forkShared.c
	$(CC) -o forkShared $(FLAG) forkShared.c
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o xyz.txt