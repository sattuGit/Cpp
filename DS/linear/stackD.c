#include <stdio.h>
#include "stackD.h"
#include<string.h>      //memset
#include<stdlib.h>      //memeory allocation 


/*Global variable */
int size_ = 0;
int* stack_ = NULL;
int head = -1;

int isValidStack(){
    return((getStackSize()>0 && getStack()!=NULL)?1:0);
}
int* getStack(void){
    return stack_;
}
void setStack(int* basePoint){
    stack_=basePoint;
}
int getStackSize(){
    return size_;
}
int setStackSize(int size){
    size_=size;
    return SUCCESS;
}
int* allocateMem(void){
    if(getStackSize()<1) return NULL;
    stack_ = (int*)malloc(getStackSize()*sizeof(int));
    if(stack_!=NULL){
        if(memset(stack_,0,size_*sizeof(int))!=stack_){
            free(stack_);
            return NULL;
        }
        return stack_;
    }else{ 
        return NULL;
    }
}

int buildStack(int size){
    setStackSize(size);
    if(allocateMem()!=NULL){
        //printf("Memory allocation is done \n");
        //displayStack();
        return SUCCESS;
    }else{
        printf("Memory allocation error \n");
        return FAIL;
    }
    return SUCCESS;
}

void displayStack(void){
    if(isValidStack()){
        printf("-----------------------\n");
        for(int i=0;i<getStackSize();++i){
            printf("[%d]->",*(stack_+i));
        }
        printf("\n-----------------------\n");
        return;
    }
    printf("No Valid Stack is available \n");    
}
