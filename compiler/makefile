CC=gcc
CFLAG=-g
#CFLAG+= -std=gnu++14
#CFLAG+= -std=gnu++98
#LFLAG = -lpthread
COMPILEONLY = -c
OBJFILES = testShareLib.o libfoo.a
TARGET = testShare testDyLib
INTERMEDIATE =  *.gch

all: $(TARGET)
testShare: $(OBJFILES)
	# -lfoo :  link share object , -L path of lib 
	$(CC) -o testShare  testShareLib.o -lfoo -L$(PWD)
testShareLib.o: testShareLib.c
	 $(CC)  $(COMPILEONLY) testShareLib.c
libfoo.a: foo.c foo.h testShareLib.c
	$(CC)  $(COMPILEONLY) foo.c
	#making archive share object 
	ar rcs -o libfoo.a foo.o

testDyLib: testShareLib.o libfoo.so 
	# link dynamic lib , only symbol entry , at run time load it form $LD_LIBRARY_PATH
	$(CC) -o testDyLib  testShareLib.o -lfoo -L$(PWD)
testShareLib.o: testShareLib.c
	$(CC)  $(COMPILEONLY) testShareLib.c
libfoo.so: foo.c foo.h testShareLib.c
	# -fpic position independent code , for dynamci lib 
	$(CC)  $(COMPILEONLY) foo.c -fpic
	# making share object .so 
	$(CC) -shared -o libfoo.so foo.o
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJFILES) foo.o libfoo.so  $(INTERMEDIATE)
