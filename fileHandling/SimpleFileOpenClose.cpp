#include<iostream>
#include<fstream>
#include<cassert>
int main(){
std::fstream ifile;
    ifile.open("makefile",std::ios::in);    
    assert(ifile.is_open());
    std::string readBuff;
    int i=0 ;
    while (!ifile.eof()){
        getline(ifile, readBuff);
        //ifile.getline(readBuff);
        std::cout<<i++<<"|"<<readBuff<<"|"<<std::endl<<std::flush;
    }   
    ifile.close();
    return 0;
}