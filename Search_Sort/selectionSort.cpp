#include <iostream>
#define MAXSIZE 10
using namespace std;
void swap(int *mArr,int p1,int p2){
    cout<<"Swap "<<mArr[p1]<<","<<mArr[p2]<<" : "<<p1<<p2<<endl;
    int tmp=mArr[p1];
    mArr[p1]=mArr[p2];
    mArr[p2]=tmp;
    return;
}
void loop(int *mArr,int len,int pos){
    cout<<"len "<<len<<" pos "<<pos<<endl;
    for(int i=pos;i<len;++i){
        if(mArr[i]>mArr[i+1])swap(mArr,i,i+1);
    }
}

void display(int *mArr,int len){
    for(int i=0;i<len-1;++i) cout<<"["<<mArr[i]<<"] "; cout<<"\n";
}
int main()
{
    int data[]={01,22,-9,9999,578,25,8797,245,0632,7};

    for(short i=0;i<MAXSIZE;++i){
        cout<<"-----------------------------------loop "<<i<<endl;
        display(data,MAXSIZE);
        loop(data,MAXSIZE,i);
    }
    display(data,MAXSIZE);
    return 0;
}
