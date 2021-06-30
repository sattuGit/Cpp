CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: puzzle
puzzle: testMidLinkList.o 
	$(CC)  -o puzzle  $(FLAG) main.cpp testMidLinkList.cpp testMidLinkList.hpp SingleLL.h
testMidLinkList.o: testMidLinkList.cpp testMidLinkList.hpp SingleLL.h
	$(CC)  -c testMidLinkList.cpp testMidLinkList.hpp SingleLL.h
.PHONY: clean
clean:
	rm -f puzzle *.o *.gch
