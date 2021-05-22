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
    stack->head_=SETEMPTY;
    stack->size_ = size;
    stack->errorCode_=0;
    
    strcpy(stack->desc_,"INIT_NOERROR\n");
    printf("%s",stack->desc_);
    stack->unitsize_=unit;
    if(allocateMem(stack)==FAIL){
        stack->errorCode_=-1;
        strcpy(stack->desc_,"Memory exception\n");
        return FAIL;
    }
    return SUCCESS;
}

int isUnderFlow(dynamicStack* stack){
    return (stack->head_==-1?1:0);
}
int isOverFlow(dynamicStack* stack){
    if(stack != NULL ){
        return(((stack->head_)==(stack->size_-1))?1:0);
    }
    setError(stack,INVALID_STACK,"INVALID_STACK");
    return FAIL;    
}
void setError(dynamicStack* stack,int err,char* msg){
    stack->errorCode_=err;
    strcpy(stack->desc_,msg);
}
int push(dynamicStack* stack,void* argData){
    if(isOverFlow(stack)){
        setError(stack,STACK_OVERFLOW,"STACK_OVERFLOW");
        return FAIL;
    }
    stack->head_=stack->head_+1;
    int jumper = stack->head_;
    
    printf("JUMPER %d\n",jumper);
    jumper=jumper*stack->unitsize_;
    int unit= stack->unitsize_;
    void *tmp = stack->dataBlock_+jumper;
    printf("%p, %d, %p\n\n",stack->dataBlock_,jumper,tmp);
    //printf("%p,%p,%p,%p",stack->dataBlock_,stack->dataBlock_+0,stack->dataBlock_+1,stack->dataBlock_+4);
     
    //void ptr=
    //printf("\ngoing to write at %d %d %p of %p",stack->head_,stack->head_*stack->unitsize_,stack->dataBlock_, stack->dataBlock_+stack->head_);
    //
    if (jumper == 0 )memcpy(stack->dataBlock_+(stack->head_*stack->unitsize_),argData,stack->unitsize_);
    else
    memcpy(stack->dataBlock_+4,argData,unit);
    

}

void printStack(dynamicStack* stack){
    //size_t index=0;
    for (int index = 0;index<=stack->head_;++index){
        printf("[%d]->",*(int*)(stack->dataBlock_+index));
        if(index==20){
         printf("PANGA in Loop \n");
            break;
        }
    }
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