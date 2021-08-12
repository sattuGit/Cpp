CC=g++
FLAG=-g
FLAG+= -std=gnu++11
TARGET= searchSort 
all: $(TARGET)
searchSort: SelectionSort.o main.o binarySearch.o
	$(CC) -o searchSort $(FLAG) SelectionSort.o main.o binarySearch.o
main.o: main.cpp
	$(CC) -c $(FLAG) main.cpp
SelectionSort.o: SelectionSort.cpp SelectionSort.h
	$(CC) -c  $(FLAG) SelectionSort.cpp SelectionSort.h
binarySearch.o: binarySearch.h binarySearch.cpp
	$(CC) -c  $(FLAG) binarySearch.cpp binarySearch.h
.PHONY: clean
clean:
	rm -f  $(TARGET) *.gch *.o 