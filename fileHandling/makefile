CC=g++
CFLAG=-g
CFLAG+= -std=c++17

COMPILEONLY = -c
OBJFILES =  fileSystem.o main.o
TARGET =  fileTest SimpleFileOpenClose
INTERMEDIATE =  *.gch

all: $(TARGET)
fileTest: $(OBJFILES)
	$(CC) -o fileTest $(CFLAG) $(OBJFILES)
main.o: main.cpp 
	$(CC) $(CFLAG) $(COMPILEONLY) main.cpp
fileSystem.o: fileSystem.cpp
	#suppport function 
	$(CC) $(CFLAG) $(COMPILEONLY) fileSystem.cpp 	
SimpleFileOpenClose: SimpleFileOpenClose.cpp
	$(CC) -o SimpleFileOpenClose $(CFLAG) SimpleFileOpenClose.cpp
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) fileTest  $(INTERMEDIATE)
