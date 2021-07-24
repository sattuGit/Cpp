#include<iostream>
#include<unistd.h> // unix system call
int main(){

    char* argument_list[] = {"satendra", "xyz.txt",NULL}; // NULL terminated array of char* strings
 
    // Ok! Will execute the command "ls -l"
    int res = execvp("touch", argument_list);
    
    std::cout<<"This line will not run (if execvp success) as execvp replaced by command"<<std::endl;

    return 0;
}