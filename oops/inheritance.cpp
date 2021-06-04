#include<iostream>
using namespace std;
#include "inheritance.h"

SimpleBase::SimpleBase(int arg=0):data(arg),pubData(arg)
{
    std::cout << "SimpleBase construtor "<<arg << std::endl;
}

SimpleDerive::SimpleDerive(int argBase, int argDerive):SimpleBase(argBase)
{
    this->data=argDerive;
    std::cout << "SimpleDerive construtor "<<argDerive << std::endl;
}
