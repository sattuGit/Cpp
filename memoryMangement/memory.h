#ifndef _SATTU_MEM_H_
#define _SATTU_MEM_H_
#include<stddef.h>
#include<iostream>
using namespace std;
class overloadNew{
    int x;
    public:
        
        /*This is "operator new" a in build function which we are going to overload, 
        int *x = new int(); this is "new operator" a keyword , we can't over load keyword  
        "new operator" first call "operator new" for memory allocation
        then it calls constructor of class
        */
        
        void* operator new (size_t size){
            std::cout << "overloaded memory allocation for"<< size<< "Unit" << std::endl;
            /*
            if you enable this line it will compile but fail at runtime  
            because member variable x need memory , so sagmentation fault would be there 
            if there is empty class with no member variable , it will work fine 
            
            */
            return nullptr;
            //return malloc(size);
            
        }
        overloadNew(){
            std::cout << "Overloaded default " << std::endl;
        }
        overloadNew(const overloadNew& arg){
            std::cout << "Overloaded copy" << std::endl;
        }
        void funFoo(int arg){
            int tmp;
            tmp=arg;
            std::cout << "DummyCall" <<tmp<< std::endl;
        }
        void setX(int x){this->x=x;}
        int getX(){return this->x;}
};

void* getMemory(size_t size);

#endif