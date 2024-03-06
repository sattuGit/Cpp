CC=gcc 
CFLAG=-std=c99
CFLAG += -g
GCPP=g++
FLAG=-std=gnu++11
FLAG += -g
OBJONLY= -c
OBJECT= singleLinkList.o linkLoop.o  #doubly.o
TARGET=linklist
all: $(OBJECT) $(TARGET) 
singleLinkList.o: singleLinkList.h singleLinkList.cpp
	$(GCPP)  $(OBJONLY) singleLinkList.h singleLinkList.cpp
linkLoop.o: linkLoop.h linkLoop.cpp
	$(GCPP)  $(OBJONLY) linkLoop.h linkLoop.cpp
doubly.o: doubly.h doubly.cpp
	$(GCPP)  $(OBJONLY) doubly.h doubly.cpp
linklist: linklist.cpp $(OBJECT)
	$(GCPP) -o linklist $(FLAG) linklist.cpp $(OBJECT)
.PHONY: clean
clean:
	rm -f $(OBJECT) $(TARGET) *.o  *.gch 