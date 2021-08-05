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
            writeBuff_10[10],
            readBuff[20];

    strcpy(writeBuff,"Hi test msg");
    strcpy(writeBuff_10,"10Size");
    /*write in piple*/
    write(pipeDesc[1],writeBuff,20*sizeof(char));
    
    /*Read from pipe*/
    read(pipeDesc[0],readBuff,20*sizeof(char));
    
    std::cout << "Read msg _"<< readBuff <<"_"<< std::endl;
    
    /*Read operation will halt if buffer is empty  */
    write(pipeDesc[1],writeBuff_10,10*sizeof(char));
    
    read(pipeDesc[0],readBuff,20*sizeof(char));
    
    std::cout << "Read msg _"<< readBuff <<"_"<< std::endl;
    
}