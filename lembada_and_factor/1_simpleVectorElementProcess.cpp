/*
Simple program for demonstrate for_each (its algorithem under C++ STL) 
*/
#include<iostream>
#include<vector>

int main(){
    
    //createing container vactor
    std::vector<int> v;
    
    
    //let's feed some data 
    for(int i=0;i<10;v.push_back(++i));

    // now we need to do set of opertion on each elemenet
    for(auto i=v.begin();i!=v.end();++i){
        if(*i%2==0){
            *i=*i*2;
        }
    }
    
    //display
    for(auto i=v.begin();i!=v.end();std::cout << *i++ << ",");
    
    return 0;
}