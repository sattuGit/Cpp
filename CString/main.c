#include<stdio.h>
#include"strFun.h"
#include<string.h> // inbuild strlen 
void main(){
    /*How to declare CStyle String
    scope of this allocaed memory is equal to scope of variable 
    */
    char c[] = "Declare String";    //'\0' will be added by compiler 
    char c1[]= "Declare String\0";
    char *c2= "Declare string";
    char *c3=NULL; 
    char c4[]={'a','b','c'};  //Special case 3*
    char c5[5]="abcde";
    
    /*String length*/
    printf("%zu,%ld\n",myStrlen(c),strlen(c));
    printf("%zu,%ld\n",myStrlen(c1),strlen(c1)); //In string lendth Str Terminator will not count 
    printf("%zu,%ld\n",myStrlen(c2),strlen(c2));
    //printf("%d",myStrlen(c3));
    //printf("%zu,%ld\n",myStrlen(c3),strlen(c3));
    printf("%zu,%ld\n",myStrlen(c4),strlen(c4));
    printf("%zu,%ld\n",myStrlen(c5),strlen(c5));
    printf("%s\n",c);
    printf("%s\n",c1);
    printf("%s\n",c2);
    //printf("%s\n",c3);
    printf("%s\n",c4);
    printf("%s\n",c5);
    return;
}