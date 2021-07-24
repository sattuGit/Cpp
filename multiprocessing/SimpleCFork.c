#include<iostream>
#include<unistd.h> //getpid
#include<thread>
int main(){
    pid_t   myPid = getpid(),
            myPPid = getppid();
    std::cout<<"START This is main program and it's process id is :"<<myPid<<" forked by "<<myPPid<<std::endl;    
    
    pid_t pid = fork();
    if(pid != 0 ){
        std::cout<<" Non Zero pid ie we are in parent "<<getpid()<<std::endl;    
        std::cout<<"Child is "<<pid<<std::endl;
        
    }else if (pid==0){
        std::cout<<" Zero pid ie we are in child "<<getpid()<<std::endl; 
        std::cout<<"Parent is "<<getppid()<<std::endl;   
        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    {
        // common area 
        pid_t   myPid = getpid(),
                myPPid = getppid();
        std::cout<<"SECOND This is main program and it's process id is :"<<myPid<<" forked by "<<myPPid<<std::endl;    
    }
    std::cout<<" Hello brother "<<std::endl;
    
    
    return 0;
}