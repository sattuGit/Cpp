CC=gcc
FLAG=-std=c99
all: stackStatic stackDynamic stackStruct

# TO-DO handling release and debug diffrently 
debug: CC += -g -DDEBUG
stackDynamic: stackD.o mainD.o
	$(CC) -o stackD stackD.o mainD.o
stackStatic: stack.o main.o
	$(CC) -o stack mainCStack.o stack_c.o
stackStruct: stackStruct.o mainStackStructure.o
	$(CC) -o stackStruct stackStruct.o mainStackStructure.o

stackStruct.o: stackStruct.c stackStruct.h
	$(CC) -c stackStruct.c 
mainStackStructure.o: mainStackStructure.c
	$(CC) -c mainStackStructure.c

stack.o: stack_c.c stack_c.h 
	$(CC) -c stack_c.c 
main.o: mainCStack.c
	gcc -c mainCStack.c 
stackD.o: stackD.c stackD.h
	$(CC) -c stackD.c 
mainD.o: mainD.c
	$(CC) -c mainD.c
clean:
	rm -f stackD stack  stackStruct *.o  *.gch 