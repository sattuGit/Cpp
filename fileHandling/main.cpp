#include<fstream>
#include<iostream>
#include"fileSystem.h"
int main(){
    
    std::string pathName = "/workspace/Cpp";
    std::string fileName =  "STLX";
    std::string line;
    
    /*check path exist*/
    if (isFileExistRSearch(pathName,fileName))std::cout<<"Exist.."<<std::endl;else std::cout<<"Oops.."<<std::endl; 
    return 0;
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