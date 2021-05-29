#include<iostream>
#include<stddef.h>
using namespace std;

void* getMemory(size_t size){
    //return malloc(size);
    return ::operator new(size);
}
