CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= testArg 
all: $(TARGET)
testArg: main.cpp
	$(CC) -o testArg $(FLAG) main.cpp
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o xyz.txt serverFIFO clientFIFO