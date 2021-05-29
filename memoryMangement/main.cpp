#include<iostream>
#include"./memory.h"
using namespace std ;

int main(){
       
    overloadNew *obj = new overloadNew( );
    obj->funFoo(5);
    //obj->setX(8);
    
    int *arr = static_cast<int*>(getMemory(sizeof(int)*10));
    for(int i=0 ;i<10;++i) cout<<"["<<*(arr+i)<<"]";cout<<endl;
    return 0;
}
