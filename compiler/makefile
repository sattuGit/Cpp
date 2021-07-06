CC=g++
CFLAG=-g
CFLAG+= -std=gnu++14
#CFLAG+= -std=gnu++98
LFLAG = -lpthread
COMPILEONLY = -c
OBJFILES = compilerMacro.h
TARGET = compile
INTERMEDIATE =  *.gch

all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC)  $(COMPILEONLY) $(OBJFILES)
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) $(INTERMEDIATE)