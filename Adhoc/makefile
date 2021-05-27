CC=g++
CXXFLAGS=-std=c++11
CXXFLAGS += -g
all: basicIOCPP
basicIOCPP: basicIOcpp.o
	$(CC) $(CXXFLAGS) -o basicIOCPP basicIO.o
basicIOcpp.o: basicIO.cpp
	g++ -c basicIO.cpp
.PHONY: clean
clean:
	rm -f basicIOCPP rm *.o
