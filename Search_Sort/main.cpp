#include<iostream>
#include "SelectionSort.h"
#include "binarySearch.h"
#include "insertionSort.h"

int main()
{
    int data[]={01,22,-9,9999,578,25,8797,245,0632,7,8,0,8};
    
    struct arr dataList;
    dataList.data = data;
    dataList.len = sizeof(data)/sizeof(int); 
    
    display(dataList);          //before sorting 
    //SelectionSort(dataList);    // sorting 
    insertionSort(dataList);
    display(dataList);          // after sorting 
    
    /*Binary Search */
    int key = 8;
    int result = binarySearch(dataList,key,0,dataList.len-1);
    std::cout << "Search of value "<<key<< " result is availble @ index "<<result << std::endl;
    return 0;
}
