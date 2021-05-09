#include<stdio.h>
#include"stackD.h"

int main()
{
    displayStack();
    if (buildStack(10)==SUCCESS){
        printf("Stack building is done .....\n");
        //displayStack();    
    }
    return 0;
}