#include<thread>
void makeDemon(void* fun,void* arg=nullptr){
    std::thread _demon(fun,arg);
    _demon.detach();
}