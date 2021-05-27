#include<stddef.h>

size_t myStrlen(const char* argStr){
    if (argStr == NULL) return -1;
    size_t index=0;
    for(;argStr[index]!='\0';++index);
    return index;
}