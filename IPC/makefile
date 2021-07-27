CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= sharedMemory
all: $(TARGET)
forkSimple: sharedMemory.c
	$(CC) -o sharedMemory $(FLAG) sharedMemory.c
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o xyz.txt