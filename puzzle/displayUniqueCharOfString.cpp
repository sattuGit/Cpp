/*
findout all unique charcter in string 
*/
#include<iostream>
#include<cstring>
int main(){
    char *str="satendrajsajdjsajd;j;saARRWTQUJEDOWSDXNn";
    size_t len = strlen(str);
    int checkBox[128];
    memset(checkBox,0,128*sizeof(int));
    for(int i=0; i<len;++i){
        ++checkBox[(short)str[i]];
    }
    std::cout<<std::endl;
    for(int i=0; i<128;++i){
        if (checkBox[i]==1)std::cout<<char(i);
    }
    std::cout<<std::endl;
    return 0;
}