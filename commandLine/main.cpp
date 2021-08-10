/*
./a.out -int 8 -str hi -float 8.8 -int 11
output:
int - 8 11
str - hi
float - 8.8
*/


#include<iostream>
#include<string.h>
#include<string>
#include<map>

#define KEY_INDICATOR '-'

int main(int argc, char **argv){    // char *argv[]

    if(argc%2==0) {
        std::cerr<<"Invalid number of argument "<<std::flush<<std::endl;
        return EXIT_FAILURE ;
    }
    
    /*Display Arg 
    for (int i = 0; i < argc; ++i) {
        std::cout<<i<<"_"<<argv[i]<<"_"<<std::endl;    
    }*/
    bool isKeyOnWait = false;
    char *tmpKey = nullptr;
    
    //std::map<std::string,std::string> argMap;
    std::map<char *,char *> argMap;
    for (int i = 1; i < argc; ++i) {
        char *tmp = argv[i];
        if(*(tmp)==KEY_INDICATOR){
            //Key block found
            if(isKeyOnWait){
                std::cerr<<"Value block missing , Invalid Arguments"<<std::endl;
                return EXIT_FAILURE;
            }
            if(strlen(tmp)<2){
                std::cerr<<"Empty Key, Invalid Arguments"<<std::endl;
                return EXIT_FAILURE;
            }
            tmpKey = tmp+1;
            isKeyOnWait=true ;
            continue;
        }
        if(isKeyOnWait){
            //N-1 was key , so N must be value 
            //argMap.insert(pair<std::string,std::string>());
            argMap.insert(std::pair<char*,char*>(tmpKey,tmp)); 
            isKeyOnWait=false;
        }
    }// argument loop ends here 
    
    std::cout<<"Map count "<<argMap.size()<<std::endl;
    for(auto i = argMap.begin(); i!=argMap.end(); ++i){
        std::cout << i->first<<"="<<i->second << std::endl;
    }    
    return 0;
}