#ifndef _SATTU_STD11_THREDDEMO_
#define _SATTU_STD11_THREDDEMO_
#include<iostream>
#include<chrono>

/*Simple C++ function*/
void simpleFunction(const size_t &count){
    for(auto i=0;i<count;++i){
        std::cout<<"simpleFunction called ["<<i<<"]"<<std::endl;
    }
}

/*Simple Function Object OR functor*/
class Functor{
    private:
        int _data;
    public:
        Functor(int arg=0):_data{arg}{}
        void operator () (const int count)  const {
            for(auto i=0;i<count;++i){
                std::cout<<"Functor called ["<<i<<"]"<<std::endl;
            } 
           // return void;       
        }
};

/*Simple lembda(named) as callable object */

auto lembda_f = [](const size_t &count)->void {for(auto i=0;i<count;++i){
                std::cout<<"lembda called ["<<i<<"]"<<std::endl;
            }   };

/*Simple Demon lembda
auto demonL = []()->void { 
    static int i=0;
	while(true){
    std::cout<<"Demon..["<<i<<"]"<<std::endl;
    std::this_thread::sleep_for (std::chrono::seconds(1));
	}
    };*/
#endif 