CC=gcc 
CFLAG=-std=c99
CFLAG += -g
GCPP=g++
FLAG=-std=gnu++11
FLAG += -g
OBJONLY= -c
OBJECT= singleLinkList.o linkLoop.o  #doubly.o
TARGET=SimpleBTree
all: $(TARGET) 
SimpleBTree: btree.h btree.cpp node.h
	$(GCPP)  -o SimpleBTree $(FLAG) btree.h btree.cpp node.h
.PHONY: clean
clean:
	rm -f $(OBJECT) $(TARGET) *.o  *.gch 