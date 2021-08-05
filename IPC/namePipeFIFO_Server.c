// ref https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_named_pipes.htm
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define PIPE_NAME "namePipe"
int main(){
    
    /*Create named pipe*/
    
    umask(0);  // reset permission mask
    
    // TO-DO , open file if and only if its exist 
    int status = mknod(PIPE_NAME,S_IFIFO|0655,0);
    if(status==-1){
        //perror("");
        std::cerr<<"Named File creation failed "<<std::endl<<std::flush;
        //if file is not exist and then mknod return error then we should terminare application
    }
    
    int fd = open(PIPE_NAME,O_RDONLY);
    if (fd==-1){
        std::cerr<<"NamedPipe open fail"<<std::endl;
        return EXIT_FAILURE;
    }
    
    int readCount =0;
    char buffer[21];
    const char *eod="END";
    while(true){
            readCount =read(fd,buffer,sizeof(buffer)-1);
            buffer[readCount]='\0';
            
            /*Check exit condition*/
            if(!strcmp(buffer,eod)){
                close(fd);
                break;  
            }
    }
    
    return 0;
}