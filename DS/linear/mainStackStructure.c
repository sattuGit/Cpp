#include "stackStruct.h"
#include<stdio.h>
//typedef struct stack_ dynamicStack; 

int main()
{
    
    dynamicStack s1;
    initStack(&s1,10,sizeof(int));
    printf("%s",s1.desc_);
    return 0;
}