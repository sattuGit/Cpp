CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= SelectionSort 
all: $(TARGET)
SelectionSort: SelectionSort.o main.o
	$(CC) -o SelectionSort $(FLAG) SelectionSort.o main.o
main.o: main.cpp
	$(CC) -c $(FLAG) main.cpp
SelectionSort.o: SelectionSort.cpp SelectionSort.h
	$(CC) -c  $(FLAG) SelectionSort.cpp SelectionSort.h
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o 