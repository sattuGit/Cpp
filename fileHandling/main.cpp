#include<fstream>
#include<iostream>
#include"fileSystem.h"
int main(){
    
    std::string pathName = "";
    std::string fileName =  "test.txt";
    std::string line;
    isPathExist();
    std::ofstream fout;
    std::ifstream fin;
    
    fout.open(fileName.c_str(),std::ios::out|std::ios::trunc);
    while(fout){
        getline(std::cin,line);
        if(line=="-1") break;
        fout<<line<<std::endl;
    }
    fout.close();
    
    
    fin.open(fileName.c_str(),std::ios::in);
    while(fin){
        getline(fin,line);
        std::cout<<line;
    }
    fin.close();
    return 0;
}