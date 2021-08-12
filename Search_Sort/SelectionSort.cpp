#include<iostream>
#include "SelectionSort.h"

void display(struct arr argList){
    int *bAdd = argList.data;
    for(int i = 0; i < argList.len; ++i){
        std::cout<<"["<<bAdd[i]<<"]";
    }
    std::cout<<std::flush<<std::endl;
}
/*-----------------SORT BLOCK START ----------------------------*/
bool compare(int v1, int v2){
    return v1<v2?true:false;
}

void SelectionSort(struct arr argList){
    for(int i =0; i<argList.len -1 ; ++i){
           //std::cout << "--------loop step "<<i << std::endl;
            int lowerIndex = i;
            for(int j=i;j<argList.len;++j){
                //std::cout << "   SubLoop " << j<<std::endl;
                if (compare(argList.data[j],argList.data[lowerIndex])){ 
                    lowerIndex=j;
                    //std::cout << "lowest update "<<lowerIndex << std::endl;
                }else{
                    
                }
            }
            if(i!=lowerIndex){
                int tmp = argList.data[i];
                argList.data[i] = argList.data[lowerIndex];
                argList.data[lowerIndex]=tmp;
                //std::cout << "Swap "<<argList.data[i]<<"  "<< argList.data[lowerIndex]<< std::endl;
            }
    }
}
