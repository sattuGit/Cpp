CC=gcc
FLAG=-std=c99
all: stackStatic stackDynamic

# TO-DO handling release and debug diffrently 
debug: CC += -g -DDEBUG
stackDynamic: stackD.o mainD.o
	$(CC) -o stackDynamic stackD.o mainD.o
stackStatic: stack.o main.o
	$(CC) -o stack mainCStack.o stack_c.o

stack.o: stack_c.c stack_c.h 
	$(CC) -c stack_c.c 
main.o: mainCStack.c
	gcc -c mainCStack.c 
stackD.o: stackD.c stackD.h
	$(CC) -c stackD.c 
mainD.o: mainD.c
	$(CC) -c mainD.c
clean:
	 rm stackCStyleFM  *.o
