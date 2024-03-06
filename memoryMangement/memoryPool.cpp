#include<iostream>
#include<cstring>
#include "memoryPool.h"
class Demo {
    private:
        int _data;
    public:
        Demo() =default;
        ~Demo() =default;
        int getData()const {return _data;}
        void setData(const int argI){ _data=argI;}
};

int main(){
    Mempool<Demo>  pool(10);
    
    Demo *t[12];
    for(auto i=0;i<12;++i){
        t[i] = pool.getSeat();
        if(t[i]!=nullptr)
        t[i]->setData(i);
        else
        std::cout << "Memory allocation error " << std::endl;
    }
    
    for(auto i=0;i<12;++i){
        if(t[i])
        std::cout << t[i]->getData() << std::endl;
    }
    
    return EXIT_SUCCESS;
}