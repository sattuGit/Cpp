#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
int globalData ; /*Global data*/

int main(){
    
    int localdata =0;
    
    int *pROll = static_cast<int*>(new int());
    *pROll=0;
    pid_t chidId = fork();
    
    if(chidId<0){
        /*Fork Fail*/
    }else{
        if(chidId){
            std::cout << "Parent "<<pROll <<"|"<<*pROll << std::endl;
            /*Parent only block*/
            for (auto i = 0; i < 10; ++i) {sleep(1);
                ++globalData;
                *pROll = i;
                ++localdata;
                std::cout << "Papa["<<i<<"|"<<localdata<<"|"<<globalData<<"|"<<*pROll<<"]" << std::endl;        
            }
            
        }else{
            std::cout << "Child"<<pROll <<"|"<<*pROll << std::endl;
            /*Child only block*/
            for(auto i =0 ;i<10;++i){sleep(2);
                ++globalData;
                ++*pROll;
                std::cout << "Beta["<<i<<"|"<<localdata<<"|"<<globalData<<"|"<<*pROll<<"]" << std::endl;
            }
        }    
    }
    {
        /*Common block*/
    
        
    }
    
    if(chidId>0){waitpid(chidId,NULL,0);}     // parent will wait for child to done 
    return 0;
}