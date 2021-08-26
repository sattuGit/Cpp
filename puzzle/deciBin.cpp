#include<iostream>
#include<math.h>
int dec2bin(const int &argInt){
    int inBin=0,
        tmp10=argInt,
        t,
        counter=0;
        //inBin = argInt%2==0?1:0;
        while(tmp10){
            t = tmp10%2;
            inBin += (pow(10,counter++) + t);
            tmp10/=10;
        }
    return inBin;
}