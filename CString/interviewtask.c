#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include"strFun.h"


//void revCopy();

void revWord(const char* inStr, char* outStr)
{
    size_t  index=0,
            atLeastOneSpace=0,
            revStrIndex=-1;
    int     markOn=-1,
            markOff=-1;
    
    for(;inStr[index]!=STR_TERMINATOR;++index)
    {
       if (inStr[index]==BLANKSPACE)
       {
           atLeastOneSpace=1;
           if(markOn != -1){
               markOff=index-1;
               for(int i=index-1; i>=markOn;--i){
                   outStr[++revStrIndex]=inStr[i];
               }
           }else{
               outStr[++revStrIndex]=inStr[index];
           }

        }
        else
        {
           if (markOn==-1){markOn=index;}

        }
    }
    if(!atLeastOneSpace)
    {
        reverseStr(inStr,outStr);
    }else{
        outStr[++revStrIndex]=STR_TERMINATOR;
    }
}

void reverseStr(const char* str,char *revStr)
{
    size_t strlen=myStrlen(str);
    char *tmp = str+strlen-1; //setting pointer at last character 
    //printf("\n%ld,%s\n",strlen,tmp);
    for (int i=0;i<strlen;++i){
        revStr[i]=*(tmp-i);
    } 
}

void removeDuplicateChar(const char* inArgs,char* outArgs, short isCase)
{
    if (inArgs==NULL) return ;
    int pool[ASCIILIMIT];
    for(int i=0;i<ASCIILIMIT;++i){pool[i]=NOVALUEFOUND;}
    int index=0,
        targetindex=0,
        tmp=0;
    for(;inArgs[index]!=STR_TERMINATOR;++index){
        tmp = inArgs[index];
        if( !isCase && (tmp>('A'-1) && tmp<('A'+26)))
        {    
            tmp+=32;
        }
        if (pool[tmp]!=VALUEFOUND)
        {
            outArgs[targetindex]=tmp;
            pool[tmp]=VALUEFOUND;
            ++targetindex;
        }
    }
    outArgs[targetindex+1]=STR_TERMINATOR;
    return ;
}