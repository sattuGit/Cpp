#include<iostream>
#include<thread>
#include<condition_variable>
#include<mutex>

bool flipFlop = false;
std::mutex _evanOdd;
std::condition_variable cv;

auto funEven = [](const int &limit)->void{
    for(auto i=0;i<limit;++i){
        std::unique_lock<std::mutex> lc(_evanOdd);
        cv.wait(lc,[]()->bool{return !flipFlop;});
        
        if(!(i&1))std::cout << "["<<i<<"]" << std::endl;
        flipFlop=true;
        cv.notify_one();
    }
};

auto funOdd = [](const int &limit)->void{
    for(auto i=0;i<limit;++i){
        std::unique_lock<std::mutex> lc(_evanOdd);
        cv.wait(lc,[]()->bool{return flipFlop;});
        
        if(i&1)std::cout << "["<<i<<"]" << std::endl;
        flipFlop=false;
        cv.notify_one();
    }
};

int main(){
    int limit = 100;
    std::thread t1(funOdd,limit);
    std::thread t2(funEven,limit);
    if(t1.joinable()) t1.join();
    if(t2.joinable()) t2.join();
    return EXIT_SUCCESS;
}