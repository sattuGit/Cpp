#ifndef __CSTACK_H
#define __CSTACK_H

#define STACK_OVERFLOW  -91
#define STACK_UNDERFLOW -92
#define STACK_EMPTY     -90
#define SIZE 5
#define SUCCESS         1
#define FAIL            0

int isOverFLow(void);
int isUnderFlow(void);
int push(int data);
int pop(void);
void printStack(void);

#endif