CC=g++
CCFLAG += -g
TARGET = main standAlone memoryPool
all: $(TARGET)
main: main.cpp memory.o
	$(CC) $(CCFLAG) -o memory  main.cpp memory.o
memory.o: memory.cpp memory.h
	$(CC) -c memory.cpp memory.h
standAlone: dynamicMemory.cpp
	$(CC) $(CCFLAG) -o dynamicMemory dynamicMemory.cpp
memoryPool: memoryPool.o
	$(CC) -o memoryPool memoryPool.o 
memoryPool.o: memoryPool.cpp memoryPool.h
	$(CC) -std=gnu++11 -c memoryPool.h memoryPool.cpp
.PHONY: clean
clean:
	rm -f *.o  *.gch $(TARGET)
