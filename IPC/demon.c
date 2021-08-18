/*
Create a normal process (Parent process)
Create a child process from within the above parent process
The process hierarchy at this stage looks like :  
    TERMINAL -> PARENT PROCESS -> CHILD PROCESS
Terminate the the parent process.
The child process now becomes orphan and is taken over by the init process.
Call setsid() function to run the process in new session and have a new group.
After the above step we can say that now this process becomes a daemon process without having a controlling terminal.
Change the working directory of the daemon process to root and close stdin, stdout and stderr file descriptors.
Let the main logic of daemon process run.
*/

#include<iostream>
#include<unistd.h>
#include<assert.h>
#include <sys/stat.h> // umask

int main(){
    pid_t cpid = fork();
    if (cpid<0){
        perror("Fork failed");
    }
    if(cpid>0){
        /*Terminate parent here, child become orphan*/
        exit(0);
    }
    std::cout<<"child process id : "<<getpid()<<" going to turn into demon"<<std::endl;
    /*Here child is become orphan*/
    umask(0); // set default process permission , no filter 
    
    /*Set new seesion for child process*/
    pid_t sid = setsid();
    assert(!(sid<0));
    /*change woring directory to ROOT */
    chdir("/");
    
    /*closing all stdin , stdout, stderr file discriptor */
    close(STDIN_FILENO);    //0 
    close(STDOUT_FILENO);   //1 
    close(STDERR_FILENO);   //2
    {
        /*Demon block */
        while(true){
            sleep(1); // sleep for some time , don't suck all resource , we can tweek it 
            
            system("echo $(date) >> /tmp/testDemon.log" ) ;   
                        
        }
    }
    return 0;
}