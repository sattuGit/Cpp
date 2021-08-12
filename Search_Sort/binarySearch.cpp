#include<iostream>
#include "binarySearch.h"

int binarySearch(struct arr &list, int key, int lbound=0, int ubound=-1){
    if(ubound<lbound){std::cerr<<"Invalid input ["<<lbound<<","<<ubound<<"]"<<std::flush<<std::endl; return -1;}
    
    int *data= list.data;
    int mid  = (lbound+ubound)/2;
    
    if(data[mid]==key){return mid;}
    if(lbound==ubound) return -1;
    
    if(data[mid]<key){
        lbound= mid+1;
    }else{
        ubound=mid-1;
    }
    return binarySearch(list,key,lbound,ubound);  // tail recurssion 
    
}