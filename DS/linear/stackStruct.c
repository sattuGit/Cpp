#include <stdio.h>
#include "stackStruct.h"
#include<string.h>      //memset
#include<stdlib.h>      //memeory allocation 


int allocateMem(dynamicStack *stack){
    if(stack->size_ <1) return FAIL;
    size_t blockSize= stack->size_ * stack->unitsize_;
    void* pMemBlock_ = malloc(blockSize);
    if(pMemBlock_!=NULL){
        
        if(memset(pMemBlock_,0,blockSize)!=pMemBlock_){
            free(pMemBlock_);
            return FAIL;
        }
        stack->dataBlock_ = pMemBlock_;
        memset(stack->desc_, '\0', sizeof(*stack->desc_));
        return SUCCESS;
    }
    return FAIL;
}

int initStack(dynamicStack *stack,size_t size,size_t unit)
{
    stack->dataBlock_=NULL;
    stack->head_=0;
    stack->size_ = size;
    stack->errorCode_=0;
    
    strcpy(stack->desc_,"INIT_NOERROR");
    printf("%s",stack->desc_);
    stack->unitsize_=unit;
    if(allocateMem(stack)==FAIL){
        stack->errorCode_=-1;
        strcpy(stack->desc_,"Memory exception\n");
        return FAIL;
    }
    return SUCCESS;
}

//buildStack(10,sizeof(int))
void* buildStack(size_t size, size_t unitsize){
/*struct stack_{
    void * dataBlock_;
    size_t head_ ;
    size_t size_;           //size_t is unsigned int, 
    short   errorCode_;
    char    desc_[25]; 
    size_t unitsize_;
};*/ 
dynamicStack t ={0,0,size,0,"",unitsize};
}



/*
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
*/