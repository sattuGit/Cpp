CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= sharedMemoryRead sharedMemoryWrite sharedMemory monitorChild pipeSimplex orphan zombie demon namePipe
all: $(TARGET)
sharedMemoryWrite: sharedMemoryWrite.c
	$(CC) -o sharedMemoryWrite $(FLAG) sharedMemoryWrite.c
sharedMemoryRead: sharedMemoryRead.c
	$(CC) -o sharedMemoryRead $(FLAG) sharedMemoryRead.c
#forkSimple: sharedMemory.c
#	$(CC) -o sharedMemory $(FLAG) sharedMemory.c
monitorChild: monitorChild.c
	#$(CC) -o monitorChild  -fpermissive $(FLAG) monitorChild.c
	$(CC) -o monitorChild   $(FLAG) monitorChild.c
pipeSimplex: pipeSimplex.c
	$(CC) -o pipeSimplex $(FLAG) pipeSimplex.c
orphan: orphan.c
	$(CC) -o orphan $(FLAG) orphan.c
zombie: zombie.c
	$(CC) -o zombie $(FLAG) zombie.c
demon: demon.c
	$(CC) -o demon $(FLAG) demon.c
namePipe: namePipeFIFO_Server.c namePipeFIFO_Client.c
	$(CC) -o serverFIFO $(FLAG) namePipeFIFO_Server.c
	$(CC) -o clientFIFO $(FLAG) namePipeFIFO_Client.c
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o xyz.txt serverFIFO clientFIFO