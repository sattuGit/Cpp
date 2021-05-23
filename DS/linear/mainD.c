#include<stdio.h>
#include"stackD.h"

int main(int argc,char** argv)
{
    if(argc>1){
        //to-do for size stack 
    }
    if (buildStack(5)==SUCCESS){
        printf("Stack building is done .....\n");
        displayStack();   
    }
     
    unsigned int choice = 0;
    while(1){
        choice = 0;
        printf("\n1 for Push \n");
        printf("2 for Pop \n");
        printf("3 for Pop \n");
        printf("9 for Exit...!!! \n");
        scanf("%u",&choice);
     
	/*   TO-DO need to handle data type before reading
	*/
        if (choice==1)
        {
            int data;
            printf("Please enter data:");
            scanf("%d",&data);
            if (push(data)==FAIL && error.errorCode ==STACK_OVERFLOW){
                printf("%s",error.desc);
                continue;
            }            
        }
        else if (choice==2){
            int tmpPop=pop();
            if(tmpPop==FAIL && error.errorCode==STACK_UNDERFLOW){
                printf("%s",error.desc);
            }
            printf("Data poped:%d",tmpPop);
        }
        else if (choice==3){
            displayStack();
        }else if (choice == 9 )
        {
        	printf("exiting...\n");
            break;
        }else{
        	printf("Invalid choice ...\n");
        }

    }
    return 0;
}