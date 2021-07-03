/******************************************************************************
Author : Satendra 
www.Satendra.info
gupta.satendra.tech@outlook.com

compare two array 
we are using intermediate array , because sizeof operator is unable to find out size of array from basedatatype pointer 
    example int a[]={1,2,3}; int *p = a; sizeof(a), and sizeof(p) will not be equal 
    so passing size along with address 
*******************************************************************************/
#include <iostream>
#include <cstring>

struct arr{
  int *arr;
  size_t buffSize;
};

bool isEqual_2(struct arr *A, struct arr *B){
    if((*A).buffSize != B->buffSize) return false;
    return memcmp(A->arr,B->arr,A->buffSize) == 0 ? true:false;
}
int main()
{
    int a[]={1,2,3,4};
    
    int b[]={1,2,3,4};
    
    struct arr A,B;
    A.arr = a;
    A.buffSize = sizeof(a);
    B.arr = b;
    B.buffSize = sizeof(b);
    
    if(isEqual_2(&A,&B))std::cout<<"Equal"<<std::endl;
    return 0;
}
