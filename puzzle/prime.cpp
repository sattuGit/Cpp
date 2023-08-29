#include <stdio.h>
/*
    Check passed argumnet is Even or odd
    return  1 if Even 
            0 if odd
*/

int isEven(int num){
    return num&1? 0 :1;    
}

/*
This function will return 
    accept int number to check 
    0 if prime number 
    1 if non prime (composit number) or invalid number 
*/
int isPrime(int num){
    if(num <  2) return 1;          // if less then 2 retuen false  
    
    if( (num != 2 ) && isEven(num)) return 1;  //return FALSE for all EVEN numbers except 2
            
    for(int i=2;i<num;++i)
        if((num%i)==0)
            return 1;
    return 0;
}

int main()
{
    for(int i=2;i<100;++i){
        printf("Number[%d] is:",i);
            if(!isPrime(i))     printf("Prime\n");
            else if (isEven(i)) printf("Even\n");
            else                printf("Odd\n");
    }
    return 0;
}
