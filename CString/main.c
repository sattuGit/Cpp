#include<stdio.h>
#include"strFun.h"
#include"interviewtask.h"
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

    printf("***************************************\n");
    char ch[]="ABCD";
    /*ch[]="XYZ";
    ch="XYZ"; ERROR as array can't be reassigne directly */
    printf("***************************************\n");
    /*remove duplicate char from string */
    char* str1="silence is a Source of great strength\0";
    char str2[strlen(str1)+1];
    memset(str2,0,strlen(str2));
    removeDuplicateChar(str1,str2,0);
    printf("%s\n%s\n",str1,str2);
    removeDuplicateChar(str1,str2,1);
    printf("%s\n%s\n",str1,str2);
    printf("***************************************\n");
    memset(str2,0,strlen(str2));
    reverseStr(str1,str2);
    printf("%s\n%s\n",str1,str2);
    printf("***************************************\n");
    /*Reverse words in a string */
    {
        char* str3 = "this is a Simple code";
        char str4[strlen(str3)+1];
        memset(str4,0,strlen(str4));
    revWord(str3,str4);
    printf("%s\n%s\n",str3,str4);
    }
    /*Test reverse string by updating itself */
    {
        char* str3 = "this is a Simple code";
        printf("String before :_%s_\n",str3);
        revStr(str3);
        printf("String After :_%s_\n",str3);
    }
    return;
}