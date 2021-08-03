CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= sharedMemory monitorChild pipeSample orphan zombie demon
all: $(TARGET)
forkSimple: sharedMemory.c
	$(CC) -o sharedMemory $(FLAG) sharedMemory.c
monitorChild: monitorChild.c
	#$(CC) -o monitorChild  -fpermissive $(FLAG) monitorChild.c
	$(CC) -o monitorChild   $(FLAG) monitorChild.c
pipeSample: pipeSample.c
	$(CC) -o pipeSample $(FLAG) pipeSample.c
orphan: orphan.c
	$(CC) -o orphan $(FLAG) orphan.c
zombie: zombie.c
	$(CC) -o zombie $(FLAG) zombie.c
demon: demon.c
	$(CC) -o demon $(FLAG) demon.c

.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o xyz.txt