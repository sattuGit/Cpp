/*
Simple program for demonstrate for_each (its algorithem under C++ STL) 
*/
#include<iostream>
#include<vector>
#include<algorithm>
// Simple Function
void fun(int &arg){
    arg = arg *(arg%2==0 ? 2:1);
}

int main(){
    
    //createing container vactor
    std::vector<int> v;
    
    
    //let's feed some data 
    for(int i=0;i<10;v.push_back(++i));

    // now we need to do set of opertion on each elemenet
    /*
    for(auto i=v.begin();i!=v.end();++i){
        if(*i%2==0){
            *i=*i*2;
        }
    }
    */
            //OR 
    
    /* for(auto i=v.begin();i!=v.end();++i){
        fun(*i);
    } */
    
    //OR 
    /*
    for(auto i=v.begin();i!=v.end();fun(*i++));
    */
    
    /* replace fun(int) with lambada 
    std::for_each(v.begin(),v.end(),fun);
    */
    
    // lambada equivelent to void fun(int)
    std::for_each(v.begin(),v.end(),[](int &arg)->void{arg = arg *(arg%2==0 ? 2:1);});
    
    //display
    for(auto i=v.begin();i!=v.end();std::cout << *i++ << ",");
    
    return 0;
}