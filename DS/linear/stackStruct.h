#ifndef _LINDSSTRUCT_H
#define _LINDSSTRUCT_H
#include<stdio.h>
#define SUCCESS 1
#define FAIL    0 
struct stack_{
    void * dataBlock_;
    size_t head_ ;
    size_t size_;           //size_t is unsigned int, 
    short   errorCode_;
    char    desc_[25]; 
    size_t unitsize_;
}; 
typedef struct stack_ dynamicStack;
#endif