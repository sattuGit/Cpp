CC=g++
CFLAG=-g
CFLAG+= -std=c++17

COMPILEONLY = -c
OBJFILES =  fileSystem.o main.o
TARGET =  fileTest
INTERMEDIATE =  *.gch

all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC) -o $(TARGET) $(CFLAG) $(OBJFILES)
main.o: main.cpp
	$(CC) $(CFLAG) $(COMPILEONLY) main.cpp
fileSystem.o: fileSystem.cpp
	#suppport function 
	$(CC) $(CFLAG) $(COMPILEONLY) fileSystem.cpp 	
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) fileTest  $(INTERMEDIATE)
