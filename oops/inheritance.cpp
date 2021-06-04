#include<iostream>
using namespace std;
#include "inheritance.h"

SimpleBase::SimpleBase(int arg):data(arg),pubData(arg),proData(arg),dupX(arg)
{
    std::cout << "SimpleBase construtor "<<arg << std::endl;
}
void SimpleBase::display()
{
    std::cout << " Base  data:"<<data << std::endl;    
    std::cout << " Base  pubData:"<<pubData << std::endl;    
    std::cout << " Base  proData:"<<proData << std::endl;    
    std::cout << " Base  dupX:"<<dupX << std::endl;    
}

SimpleDerive::SimpleDerive(int argBase, int argDerive):SimpleBase(argBase)
{
    this->data=argDerive;
    dupX=argDerive;
    std::cout << "SimpleDerive construtor "<<argDerive << std::endl;
}
SimpleDerivePubic::SimpleDerivePubic(int argBase, int argDerive):SimpleBase(argBase)
{
    this->data=argDerive;
    dupX=argDerive;
    std::cout << "SimpleDerive construtor "<<argDerive << std::endl;
}
void SimpleDerivePubic::display()
{
    std::cout << "Drived data"<<this->data<< std::endl;
    std::cout << "Drived dupX"<<dupX << std::endl;
    //std::cout << "Base data"<<SimpleBase::data << std::endl;
    std::cout << "Base pubData"<<pubData << std::endl;
    std::cout << "Base proData"<<proData << std::endl;
    std::cout << "Base dupX"<<SimpleBase::dupX << std::endl;
    
    /* Private member can't be access of Base
    std::cout << "access private of base :"<<SimpleBase::data << std::endl;*/
}

void SimpleDerive::display()
{
    std::cout << "Drived data"<<this->data<< std::endl;
    std::cout << "Drived dupX"<<dupX << std::endl;
    //std::cout << "Base data"<<SimpleBase::data << std::endl;
    std::cout << "Base pubData"<<pubData << std::endl;
    std::cout << "Base proData"<<proData << std::endl;
    std::cout << "Base dupX"<<SimpleBase::dupX << std::endl;
    
    /* Private member can't be access of Base
    std::cout << "access private of base :"<<SimpleBase::data << std::endl;*/
}
