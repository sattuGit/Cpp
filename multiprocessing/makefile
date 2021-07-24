CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= forkSimple childControl
all: $(TARGET)
forkSimple: SimpleCFork.c
	$(CC) -o forkSimple $(FLAG) SimpleCFork.c
childControl: childControl.c
	$(CC) -o childControl $(FLAG) childControl.c
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o