CC=g++
FLAG=-g
FLAG+= -std=gnu++11
FLAG+= -pthread
TARGET= std_11_thread
OBJECTS= SimpleThreadPrg.cpp callableObjectsDemo.h
all: $(TARGET)
$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(FLAG) $(OBJECTS)
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o
