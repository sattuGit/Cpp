#include<iostream>

bool palindrome(const std::string &argStr){
    int len=argStr.length();
    for(auto i=0;i<len/2;++i){
        if(argStr[i]!=argStr[len-1-i]) return false;       
    }
    return true;
}

bool palindrome(const int &argInt){
    int tNum=argInt,
        revSum=0,
        t;
    while(tNum){
        t = tNum%10;
        revSum=revSum*10+t;
        tNum/=10;
    }
    std::cout<<argInt<<"|"<<revSum<<std::endl;
    return argInt==revSum?true:false;
}

