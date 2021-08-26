CC=g++
FLAG=-g
FLAG+= -std=gnu++11
all: puzzle
puzzle: testMidLinkList.o palindrome.o deciBin.o main.cpp
	$(CC)  -o puzzle  $(FLAG) main.cpp testMidLinkList.o palindrome.o deciBin.o #testMidLinkList.hpp SingleLL.h 
testMidLinkList.o: testMidLinkList.cpp testMidLinkList.hpp SingleLL.h
	$(CC)  -c testMidLinkList.cpp testMidLinkList.hpp SingleLL.h
palindrome.o: palindrome.cpp palindrome.h
	$(CC) -c palindrome.cpp palindrome.h
deciBin.o: deciBin.h deciBin.cpp
	$(CC) -c deciBin.h deciBin.cpp
.PHONY: clean
clean:
	rm -f puzzle *.o *.gch
