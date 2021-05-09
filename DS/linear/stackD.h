#ifndef __CSTACKD_H
#define __CSTACKD_H
#include <stddef.h>
#define STACK_OVERFLOW  -91
#define STACK_UNDERFLOW -90
#define STACK_EMPTY     -93
#define SIZE 5
#define SUCCESS         1
#define FAIL            0
struct stackError
{
    char *desc;
    int errorCode;
} error;

int getHead(void);
int isOverFlow(void);
int isUnderFlow(void);
int push(int);
int pop(void);
int* getStack(void);
void setStack(int* );
void displayStack(void);
int isValidStack(void);
int getStackSize(void);
int setStackSize(int);
int* allocateMem();
//int initStack( void );
int buildStack(int);

//int isOverFLow(void);
//int isUnderFlow(void);

//int push(int data);
//int pop(void);
//void printStack(void);
#endif