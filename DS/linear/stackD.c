#include <stdio.h>
#include "stackD.h"
#include<string.h>      //memset
#include<stdlib.h>      //memeory allocation 


/*Global variable */
int size_ = 0;
int* stack_ = NULL;
int head_ = -1;
//TO-DO need to improve error return with error bit structure 
//known issue : if we are passing 0 as data it will false fail
void resetError(void){
    error.errorCode=0;
}
int pop(){
    resetError();
    if(isUnderFlow()){
        error.errorCode=STACK_UNDERFLOW;
        error.desc="There is no data to pop\n";
        return FAIL;
    }
    int tmp=*(stack_+getHead());
    stack_[head_]=0;
    --head_;
    return(tmp);
}
int push(int data){
    resetError();
    if (isOverFlow()){
        error.errorCode=STACK_OVERFLOW;
        error.desc="There is no memory in stack \n";
        return FAIL;
    };
    ++head_;
    *(stack_+getHead())=data;           
}
int getHead(){
    return head_;
}
int isOverFlow()
{
    return (getHead()== getStackSize()-1)?1:0;
}
int isUnderFlow(){
    return(getHead()==-1?1:0);
}
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
    error.errorCode=0;
    setStackSize(size);
    if(allocateMem()!=NULL){
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
