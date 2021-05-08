#include <stdio.h>
//#include "stack_c.h"
#include "stack_c.h"
int main(int argc, char** argv)
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
        if (choice==1)
        {
            if (isOverFLow()==SUCCESS)
            {
                printf("Space Excepton..\n");
            }else
            {  
                int data;
                printf("Plese enter valid integer to push \n");
                scanf("%d",&data);
                if (push(data)== data)
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
    return 0;
}
