CC=g++
CXXFLAGS=-std=c++11
CXXFLAGS += -g
all: basicIOCPP DSLinear

basicIOCPP: basicIOcpp.o
	$(CC)  $(CXXFLAGS) -o basicIOCPP basicIO.o
basicIOcpp.o: basicIO.cpp
	$(CC) -c basicIO.cpp
DSLinear:
	make -C ./DS/linear
.PHONY: clean	
clean:
	make -C ./DS/linear clean
	rm basicIOCPP *.o 
	