CC=g++
CFLAG=-g
CFLAG+= -std=gnu++14

COMPILEONLY = -c -g
OBJFILES = core.o libdistrubution.so 
TARGET = core
INTERMEDIATE =  *.gch

all: $(TARGET)
$(TARGET): $(OBJFILES)
	# link dynamic lib , only symbol entry , at run time load it form $LD_LIBRARY_PATH
	#-ldl enable dynamic loading 
	$(CC) -o core $(CFLAG)  core.o -ldl
core.o: core.cpp
	$(CC)  $(COMPILEONLY) core.cpp
libdistrubution.so: distrubution.cpp
	# -fpic position independent code , for dynamci lib 
	$(CC)  $(COMPILEONLY) distrubution.cpp -fpic
	# making share object .so 
	$(CC) -shared -o libdistrubution.so distrubution.o
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) distrubution.o libdistrubution.so  $(INTERMEDIATE)
