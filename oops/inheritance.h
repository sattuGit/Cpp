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
        virtual void dynamicBind(){std::cout<<"SimpleBase::dynamicBind Called"<<std::endl;}
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
         void dynamicBind(){std::cout<<"SimpleDerivePubic::dynamicBind Called"<<std::endl;}
        /*above virtual is not making any effect if base and derive both are virtaul */
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