CC=g++
CFLAG=-g
CFLAG+= -std=gnu++11
#CFLAG+= -std=gnu++98
LFLAG = -lpthread
COMPILEONLY = -c
OBJFILES = mainDP.o testDP.o
TARGET = dpattern
INTERMEDIATE =  *.gch

all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC)  $(CFLAG)  -o $(TARGET) $(OBJFILES) $(LFLAG)
mainDP.o: mainDP.cpp 
	$(CC) $(COMPILEONLY) mainDP.cpp $(LFLAG)
testDP.o: factory.o single.o testDP.cpp testDP.h 
	$(CC) $(COMPILEONLY) testDP.cpp testDP.h $(LFLAG)
factory.o: DPF.h 
	$(CC) $(COMPILEONLY) DPF.h
single.o: SINGLE.h
	$(CC)  $(COMPILEONLY) SINGLE.h $(LFLAG)
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) $(INTERMEDIATE)