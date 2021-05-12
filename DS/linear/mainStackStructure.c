#include "stackStruct.h"
#include<stdio.h>
//typedef struct stack_ dynamicStack; 

int main()
{
    
    dynamicStack s1;
    initStack(&s1,10,sizeof(int));
    
    printf("%s",s1.desc_);
    if(isOverFlow(&s1))printf("---------");
    if(isUnderFlow(&s1))printf("++++++++");
    printf("........................");
    int tmp=10;
    push(&s1,&tmp);
    int tmp2=20;
    push(&s1,&tmp2);
    printStack(&s1);
    
    
    return 0;
}