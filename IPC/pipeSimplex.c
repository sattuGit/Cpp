#include<iostream>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(){
    
    /*read write descriptor 0 for read, 1 for write */
    int pipeDesc[2];
    
    int status =  pipe(pipeDesc);
    if(status==-1){
        std::cout << "pipe failed " << std::endl;
        return EXIT_FAILURE;
    }    
    
    char    writeBuff[20],
            readBuff[20];

    
    
    pid_t pid=fork();
    if(pid<0){
        perror("Fork Failed") ;// std:cerr
        return EXIT_FAILURE;
    }
    
    if(pid){
        /*Parent block*/
        strcpy(writeBuff,"Hi test msg");
        write(pipeDesc[1],writeBuff,20*sizeof(char));
        strcpy(writeBuff,"2nd Hi test msg");
        write(pipeDesc[1],writeBuff,20*sizeof(char));
        return EXIT_SUCCESS;
    }
    else{
        /*Child block*/
        sleep(1);
        read(pipeDesc[0],readBuff,20*sizeof(char));
        std::cout << "Read msg _"<< readBuff <<"_"<< std::endl;
        read(pipeDesc[0],readBuff,20*sizeof(char));
        std::cout << "Read msg _"<< readBuff <<"_"<< std::endl;
        return EXIT_SUCCESS;
    }
    
    return EXIT_SUCCESS;
}

/*

Pipe can be used in related process only (forked parent child )

Simple pipe work in one direction , if you wish to setup 2-way communication 
we need to create two pipe 
pipe x , pipe y 

process A, process B (child)

A read x[0], write y[1]
B read y[0], write x[1]

*/