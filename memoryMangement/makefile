CC=g++
CCFLAG += -g
all: main standAlone
main: main.cpp memory.cpp memory.h
	$(CC) $(CCFLAG) -o memory  memory.cpp memory.h main.cpp 
standAlone: dynamicMemory.cpp
	$(CC) $(CCFLAG) -o dynamicMemory dynamicMemory.cpp
.PHONY: clean
clean:
	rm *.o  *.gch memory dynamicMemory