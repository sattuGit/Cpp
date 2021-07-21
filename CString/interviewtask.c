#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include"strFun.h"
#include"../log/log.h"

void revWord(const char* inStr, char* outStr)
{
    TRACE("\nSize %lu,%lu\n",strlen(inStr),strlen(outStr));
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
    for (int i=0;i<strlen;++i){
        revStr[i]=*(tmp-i);
    } 
}
void revStr(char* str) /*update same string*/{
    size_t len = strlen(str);
    char tmp;
    --len;
    TRACE("[%lu]::%s\n",len,str);
    for(int i =0 ;i<(len/2)+1;++i){
        TRACE ("%d,",i);
        TRACE("%c <=> %c ,",str[i],str[len-i]);
        TRACE("\n");
        tmp= *(str+i);
        TRACE("%c ,",tmp);
        *(str+i)= *(str+len-i);
       // *(str+i)=*(str+len-i);
        //str[len-i]=tmp;
       // *(str+len-i)=tmp;
        
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
