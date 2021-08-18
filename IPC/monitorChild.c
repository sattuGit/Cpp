#include<iostream>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    pid_t pidChild  = fork();
    if (pidChild<0){
        std::cout << "Fork failed" << std::endl;
    }else if (pidChild==0){
        /*Parents block*/
        sleep(5);
        std::cout << "Parents wake up "<<getppid()<<"->"<<getpid() << std::endl;
        
    }else{
        return 9;
        /*Child only area
        pid_t gChild = fork();
        if(gChild){
            //child area
            sleep(2);
            std::cout << "Child wake up "<<getppid()<<"->"<<getpid() << std::endl;
            // wait will only wait for any one return of child ,in case of no child return immeditly  
            int status;
            wait(&status);
            std::cout << "child catch "<<std::hex<<status << std::endl;
            return 7;
        }
        else{
            // G child area
            sleep(3);
            std::cout << "Gchild wake up "<<getppid()<<"->"<<getpid() << std::endl;
            return 6;
        }*/
    }
    /*Here onwards common area */
    int status ; 
    
    /*wait for specific pid, by default wait for termination i.e.0
    WIFEXITED(status) is terminate normally (no signalled )
    WEXITSTATUS(status) == 0  return 0 ie success 
    */
    pid_t rpid = waitpid(pidChild,&status,0);
    
    if (!WIFEXITED(status)){
        std::cout << "Process terminated by signalled" << std::endl;
    }
    if(WEXITSTATUS(status)==0){
        std::cout << "return success ie ZERO" << std::endl;
    }else{
        std::cout << "return Unsuccess ie "<<status << std::endl;
    }
    
    return 0;
}
