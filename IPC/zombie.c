#include<iostream>
#include<unistd.h>
#include<assert.h>

int main(){
    std::cout<<"Current process : "<<getppid()<<"->"<<getpid()<<std::endl;
    
    pid_t pidChild = fork();
    assert(!(pidChild<0) );
    
    if(pidChild==0){
        std::cout<<"In child going to sleep "<<getppid()<<"->"<<getpid()<<std::endl;
        
        sleep(5);
        exit(0);
    }else{

        std::cout << "Parent "<<getppid()<<"->"<<getpid() << std::endl;
        sleep(7);
        
    }
    system("ps -f | grep zombie");
    return 0;
}