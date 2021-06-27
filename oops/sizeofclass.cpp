#include<iostream>
class A{
    
    int x;
    virtual void fun(){int x ;}
    //int x;
    static int z;
};
class B: virtual A{
    int y;
};
int main(){
    A a;
    B b;
    std::cout<<sizeof(A)<<std::endl;
    std::cout<<sizeof(a)<<std::endl;

    std::cout<<sizeof(B)<<std::endl;
    std::cout<<sizeof(b)<<std::endl;

    return 0;
}
/*
class A  ::  4+8(VTPR) => 12 + padiing 4 => 16
class B  ::  class A + 4 + 8(VTPR)  = 16+12 = 28 + padding => 32  
*/