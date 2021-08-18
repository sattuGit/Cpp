/*   Create Server for POC share memory 
Create the shared memory segment or use an already created shared memory segment (shmget())

Attach the process to the already created shared memory segment (shmat())

Detach the process from the already attached shared memory segment (shmdt())

Control operations on the shared memory segment (shmctl())

*/

#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
//ftok(): is use to generate a unique key.
#define SHM_KEY 0x1234

#define MSG_SIZE 1024


struct pack{
    int len;
    bool isDone;
    char buffer[MSG_SIZE]; 
};

int main(){
    
    /*We are using static key for share meory*/
    
    /*Generate share memory */
    int shareMemDesc = shmget(SHM_KEY,sizeof(pack),0644|IPC_CREAT);
    if(shareMemDesc == -1) {
        std::cerr<<" shared memory creation failed "<<std::flush<<std::endl;
        return EXIT_FAILURE;
    }
    
    /*Attach memory to process*/
    struct pack *pShm ;
    // get memory pointer for shared memory address 
    pShm = static_cast<pack*>(shmat(shareMemDesc,NULL,0));
    if(pShm == NULL || pShm == nullptr){
        perror("share memory attachment failed ");
        return EXIT_FAILURE;
    }
    
    /* read memory */
    while(!pShm->isDone){
        std::cout << "-----------" << std::endl;
        sleep(1);
        if(pShm->len <0){
            perror("Read Error ");
            return EXIT_FAILURE;
        }
        std::cout<<"READ|"<<pShm->len<<"|"<<pShm->buffer<<"|"<<std::flush<<std::endl;
    }
    
    /*detach memory*/
    if(shmdt(pShm)==-1){
        perror("shmdt call failed");
        return EXIT_FAILURE;
    }
    
    
    return 0;
}

