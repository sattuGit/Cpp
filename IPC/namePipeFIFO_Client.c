// ref https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_named_pipes.htm
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define PIPE_NAME "namePipe"
int main(){
    
    /*Client will only read , not create pipe */
    int fd = open(PIPE_NAME,O_WRONLY);
    if (fd==-1){
        std::cerr<<"NamedPipe open fail"<<std::endl;
        return EXIT_FAILURE;
    }
    
    int readCount =0;
    const char *eod="END";
    
    int buffLen=-1;
    char buffer[21];
    
    while(true){
        std::cout<<"Feed data "<<std::endl;
        fgets(buffer,sizeof(buffer),stdin);
        buffLen = strlen(buffer);
        buffer[buffLen-1]='\0';
        
        
        //readCount =read(fd,buffer,sizeof(buffer)-1);
        //buffer[readCount]='\0';
            
        write(fd,buffer,buffLen);
        
        /*Check exit condition*/
        if(!strcmp(buffer,eod)){
            close(fd);
            break;  
        }
    }
    
    return 0;
}