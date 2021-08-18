/*
Simple program for demonstrate for_each (its algorithem under C++ STL) 
*/
#include<iostream>
#include<vector>
#include<algorithm>

int main(){
    
    //Named lembada function 
    
    auto _f2 = [](int  & x){std::cout << "inside Named lembada Function ["<<x<<"]" << std::endl;};

    std::vector<int> v;
    for(auto i = 0;i<10;v.push_back(++i));
    
    std::for_each(v.begin(),v.end(),_f2);
    
    return 0;
}