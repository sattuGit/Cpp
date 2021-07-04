#include<iostream>
#include "testPointers.h"

int main(){
    
    //if (!testSmartPointer())    std::cout<<"ERROR in testSmartPointer"<<std::endl;
    //if (!testUniquePointer())   std::cout<<"ERROR in testUniquePointer"<<std::endl;
    if (!testSharePointer())    std::cout<<"ERROR in testSharePointer"<<std::endl;
    if (!testWeekPointer())     std::cout<<"ERROR in testWeekPointer"<<std::endl;
    if (!testAutoPointer())     std::cout<<"ERROR in testAutoPointer"<<std::endl;
    return 0;
}