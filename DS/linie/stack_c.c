#include <stdio.h>
#include "stack_c.h"

unsigned int stack[10];
short head=-1;

int isOverFLow(void){
    //printf("CALLED %d,%d",head,SIZE);
	return ((head==(SIZE-1))?SUCCESS:FAIL);
}

int isUnderFlow(void){
    return ((head==-1)?1:0);
}

int push(int data){
	if(isOverFLow()){
    	return STACK_OVERFLOW;
	}
    stack[++head]=data;
	return data;
}

int pop(void){
    if(isUnderFlow()){ return STACK_UNDERFLOW;}
    int tmp = stack[head];
    stack[head]=0;
    --head;
    return(tmp);
}

void printStack(void){
	for(int i=0;i<SIZE;++i)
		printf("[%d]",stack[i]);
	printf("\n");
}