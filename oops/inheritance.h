#ifndef _SATTU_INTF_H_
#define _SATTU_INTF_H_
#include <iostream>
//using namespace std;  we should avaoid include any samespace in header file , if require use specifc 

class SimpleBase{
    //default private 
    int data;
    public:
        int pubData;
         SimpleBase(int);
};

class SimpleDerive:public SimpleBase
{
    int data;
    public:
    SimpleDerive(int,int);
};

#endif