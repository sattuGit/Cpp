#include<iostream>
#include "SelectionSort.h"

int main()
{
    int data[]={01,22,-9,9999,578,25,8797,245,0632,7};
    
    struct arr dataList;
    dataList.data = data;
    dataList.len = sizeof(data)/sizeof(int); 
    
    display(dataList);          //before sorting 
    SelectionSort(dataList);    // sorting 
    display(dataList);          // after sorting 
    return 0;
}
