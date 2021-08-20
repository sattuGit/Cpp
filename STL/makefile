CC=g++
CFLAG=-g
CFLAG+= -std=gnu++11
#CFLAG+= -std=gnu++98
COMPILEONLY = -c
#OBJFILES = STL_list.o STL_vector.o 
TARGET = STL_Array STL_list STL_vector 
INTERMEDIATE =  *.gch

all: $(TARGET) 
STL_Array: STL_Array.cpp customObj.h
	$(CC) $(CFLAG) -o STL_Array STL_Array.cpp
STL_list: STL_list.cpp customObj.h
	$(CC) $(CFLAG) -o STL_list STL_list.cpp
STL_vector: STL_vector.cpp customObj.h
	$(CC) $(CFLAG) -o STL_vector STL_vector.cpp

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) $(INTERMEDIATE) *.o