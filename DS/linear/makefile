all: stackCStyleFM

stackCStyleFM: stack_c.o mainCStack.o
	 gcc -o stackCStyleFM stack_c.o mainCStack.o

stack_c.o: stack_c.c
	 gcc -c stack_c.c
mainCStack.o: mainCStack.c
	gcc -c mainCStack.c
     
clean:
	 rm stackCStyleFM  *.o