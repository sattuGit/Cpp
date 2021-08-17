#include <iostream>
#include "insertionSort.h"
#include "SelectionSort.h"

bool insertionSort(arr& list){
    int *data = list.data;
    size_t len = list.len;
    
    /*Insertion sort begin here*/
    for(auto i =1;i<len;++i){
        int key=data[i];
        int j=i-1;
        while(j>=0 && data[j]>key){
            data[j+1]=data[j];
            --j;
        }
        data[j+1]=key;
    }
 
    return true ;
}