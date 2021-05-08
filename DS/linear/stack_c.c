#include <stdio.h>
#include <stdlib.h>

#define STACK_OVERFLOW  -91
#define STACK_UNDERFLOW -92
#define STACK_EMPTY     -90
#define SIZE 10
#define SUCCESS         1
#define FAIL            0

unsigned int stack[10];
short head=-1;

int isOverFLow(){
	return ((head==(SIZE-1))?1:0);
}

int isUnderFlow(){
    return ((head==-1)?1:0);
}

int push(int data){
	if(isOverFLow()){
    	return STACK_OVERFLOW;
	}
    stack[++head]=data;
	return SUCCESS;
}

int pop(){
    if(isUnderFlow()){ return STACK_UNDERFLOW;}
    int tmp = stack[head];
    stack[head]=0;
    --head;
    return(tmp);
}

void printStack(){
	for(int i=0;i<SIZE;++i)
		printf("[%d]",stack[i]);
	printf("\n");
}

void main(int argc, char** argv)
{
    unsigned int choice = 0;
    while(1){
        choice = 0;
        printf("1 for Push \n");
        printf("2 for Pop \n");
        printf("3 for Exit...!!! \n");
        scanf("%u",&choice);
     
	/*   TO-DO need to handle data type before reading
	*/
        if (choice==1){
            if (isOverFLow()==STACK_OVERFLOW){
                printf("Space Excepton..\n");
            }else
            {   
                int data;
                printf("Plese enter valid integer to push \n");
                scanf("%d",&data);
                if (push(data)== SUCCESS)
                {
                    printf("Inserted...\n");
                }else{
                    printf("Unknown error ...\n");
                }
            }
            
            
        }
        else if (choice==2){
            int tmp = pop();		
            if (tmp==STACK_UNDERFLOW){
                printf("NO DATA FOUND");
            }else{
				printf("Data Poped %d",tmp);;
			}

        }else if (choice == 3 )
        {
        	printf("exiting...\n");
            break;
        }else{
        	printf("Invalid choice ...\n");
        }
		printStack();
    }
    return;
}
