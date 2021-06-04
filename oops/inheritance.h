#ifndef _SATTU_INTF_H_
#define _SATTU_INTF_H_
#include <iostream>
//using namespace std;  we should avaoid include any samespace in header file , if require use specifc 

class SimpleBase{
    //default private 
    int data;
    public:
        int dupX;
        int pubData;
        SimpleBase(int);
        void display();
    protected:
        int proData;
};

class SimpleDerivePubic : public SimpleBase
{
        int data;
    public:
        int dupX;
        SimpleDerivePubic(int,int);
        void display();
};

class SimpleDerive:  SimpleBase
{
        int data;
    public:
        int dupX;
        SimpleDerive(int,int);
        void display();
};

#endif