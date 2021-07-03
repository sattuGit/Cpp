#include<iostream>
#include "testPointers.h"

int main(){
    
    //if (!testSmartPointer())    std::cout<<"ERROR in testSmartPointer"<<std::endl;
    //if (!testUniquePointer())   std::cout<<"ERROR in testUniquePointer"<<std::endl;
    if (!testSharePointer())    std::cout<<"ERROR in testSharePointer"<<std::endl;
    
    return 0;
}