CC=gcc
CCXX=g++
CCFLAG=-std=c99
CCXXFLAG=-std=c++11
DEBUGON= -g

all: main
main: template.cpp
	$(CCXX) $(CCXXFLAG) $(DEBUGON) -o template template.cpp

.PHONY: clean
clean:
	rm -f *.o *.gch template
