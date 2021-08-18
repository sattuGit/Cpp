#include<iostream>
#include<unistd.h>
#include<assert.h>

int main(){
    std::cout<<"Current process : "<<getppid()<<"->"<<getpid()<<std::endl;
    
    pid_t pidChild = fork();
    assert(!(pidChild<0) );
    
    if(pidChild==0){
        std::cout<<"In child going to sleep "<<getppid()<<"->"<<getpid()<<std::endl;
        
        for (int i = 0; i <10; i++) {
            
            if(getppid()==1){
                std::cout << "God is father of all mankind "<<getppid() << std::endl;    
            }else{
                std::cout << "Jaanta hai mere baap kaun hai ?"<<getppid() << std::endl;    
            }
            sleep(1);
        }
        std::cout<<"In child wakeup "<<getppid()<<"->"<<getpid()<<std::endl;
        system("ps -f | grep orphan");
    }else{

        std::cout << "Parent "<<getppid()<<"->"<<getpid() << std::endl;
        sleep(5);
        
    }
    return 0;
}