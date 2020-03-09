#include <iostream>

using namespace std;

int main()
{
    cout<<"This is demostration for C++ literals\n";
    
    
    // integer literals 99
    auto x = 99;  // its similer to int x as int is default numeric literals
    cout<<"Size of int is "<<sizeof(int)<<" size of auto x = 99 "<<sizeof(x)<<endl;
    
    auto xBase10  = 75; //75 in base10  is 75 
    int xBase8   = 075; //75 in base 8  is 61
    int xBase16  = 0x75;//75 in base 16 is 117
    auto xBase162 = 0x4b;
    cout<<"base 10 size is "<<sizeof(xBase10)<<"  base 8 size is "<<sizeof(xBase8)<<"  base 16 size is "<<sizeof(xBase16)<<endl;
    cout<<xBase10<<":"<<xBase8<<":"<<xBase16<<endl;
    cout<<sizeof(xBase162)<<":"<<xBase162<<endl;
    
    
    /*deling with signed or unsigned and long suffix*/
    
    auto xInt           =   75;
    auto xUnsignedInt   =   75u;    // 'u' OR 'U' both will behave in same way for numerical literals
    auto xLong          =   75L;    //'L' OR 'l' are equal for numeric literals
    auto xUnsignedLong  =   75Lu;   // combination unsigned long , 75lu, 75ul, 75Lu, 75LU, 75lU all are equal
    cout<<": size of xInt :"<<sizeof(xInt)<<" "<<xInt<<": size of xUnsignedInt :"<<sizeof(xUnsignedInt)<<" "<<xUnsignedInt<<": size of xLong :"<<sizeof(xLong)<<" "<<xLong<<": size of xUnsignedLong :"<<sizeof(xUnsignedLong)<<" "<<xUnsignedLong<<endl;
    
    /*floating point */
    auto xf =3.2f;  //'f' OR 'F' are equal both will express float literals
    auto xld = 3.2L; // 'l' OR 'L' are equal, both will create Long double
    auto xd = 3.2;  // default is double 
    cout<<"size of float "<<sizeof(xf)<<" "<<xf<<" : "<<"size of long double "<<sizeof(xld)<<" "<<xld<<" : "<<"size of  double "<<sizeof(xd)<<" "<<xd<<endl;
    //NOTE : f L and e are floating point literals, e is used for represent 10BaseE
    auto xE= 6.02e23; // 6.02 * 10 ^23
    cout<<"sizeof xE "<<sizeof(xE)<<":"<<xE<<endl;
    
    return 0;
}
