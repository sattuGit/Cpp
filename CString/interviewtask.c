#include<stddef.h>
#include<stdio.h>
void removeDuplicateChar(const char* inArgs,char* outArgs, short isCase)
{
    if (inArgs==NULL) return ;
    int pool[256];
    for(int i=0;i<256;++i)pool[i]=0;
    int index=0,
        targetindex=0,
        tmp=0;
    for(;inArgs[index]!='\0';++index){
        tmp = inArgs[index];
        if( !isCase && (tmp>64 && tmp<(65+26)))
        {    
            tmp+=32;
        }
        if (pool[tmp]!=1)
        {
            outArgs[targetindex]=tmp;
            pool[tmp]=1;
            ++targetindex;
        }
    }
    outArgs[targetindex+1]='\0';
    return ;
}