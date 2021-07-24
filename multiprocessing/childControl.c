#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
int main (){
    std::cout << " Start Point Only for parents " << std::endl;
    pid_t pid =fork();
    if(pid){
        std::cout << "Only for parents after child fork"<<getpid() << std::endl;
        
        /*We need to hold our program to wait till child done
        similer to thread's join() 
        */
        waitpid(pid,NULL,0); 
    }else{
        std::cout << "Only for child , child starting point "<<getpid() << std::endl;
        for (int i = 0; i < 10; i++) {
            sleep(1);
        }
        std::cout << "Child only block done " << std::endl;
    }
    {
        std::cout << "Common after child fork " << std::endl;
    }
    return 0;
}