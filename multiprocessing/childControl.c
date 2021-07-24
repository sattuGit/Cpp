#include<iostream>
#include<unistd.h>
int main (){
    std::cout << " Start Point Only for parents " << std::endl;
    if(fork()){
        std::cout << "Only for parents after child fork" << std::endl;
    }else{
        std::cout << "Only for child , child starting point " << std::endl;
    }
    {
        std::cout << "Common after child fork " << std::endl;
    }
    return 0;
}