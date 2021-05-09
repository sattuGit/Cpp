CC=gcc
FLAG=-std=c99
all: stackCStyleFM

# TO-DO handling release and debug diffrently 
debug: CC += -g -DDEBUG
stackCStyleFM: stack.o main.o
	#$(CC) -o stackCStyleFM mainCStack.o stack_c.o
	$(CC) -o stackCStyleFM mainCStack.o stack_c.o
stack.o: stack_c.c stack_c.h 
	$(CC) -c stack_c.c 
main.o: mainCStack.c
	gcc -c mainCStack.c 
clean:
	 rm stackCStyleFM  *.o