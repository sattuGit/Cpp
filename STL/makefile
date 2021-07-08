CC=g++
CFLAG=-g
CFLAG+= -std=gnu++14
#CFLAG+= -std=gnu++98
COMPILEONLY = -c
OBJFILES = compilerMacro.h
TARGET = compile
INTERMEDIATE =  *.gch

all: $(TARGET)
$(TARGET): $(OBJFILES)
	$(CC)  --version
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) $(INTERMEDIATE)