#ifndef _LINDSSTRUCT_H
#define _LINDSSTRUCT_H
#include<stdio.h>
#define SUCCESS 1
#define FAIL    0
#define SETEMPTY -1 
#define STACK_OVERFLOW  -9
#define STACK_UNDERFLOW -8
#define INVALID_STACK   -2
struct stack_{
    void * dataBlock_;
    int  head_ ;
    size_t size_;           //size_t is unsigned int, 
    short   errorCode_;
    char    desc_[25]; 
    size_t unitsize_;
}; 
typedef struct stack_ dynamicStack;

int allocateMem(dynamicStack *);
int initStack(dynamicStack *,size_t,size_t);
int isUnderFlow(dynamicStack*);
int isOverFlow(dynamicStack*);
void setError(dynamicStack*,int,char*);
int push(dynamicStack*,void*);
void printStack(dynamicStack*);
#endif