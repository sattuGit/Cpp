/*
source http://www.cplusplus.com/doc/tutorial/constants/
*/
#include <iostream>
#include<string>

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
    
    
    /*Character OR string literals*/
    auto xc ='x'; //Character
    string xs = "xyzpqddddasadasfasfasfafafafafa";//string
    cout<<sizeof(xc)<<":"<<sizeof(xs)<<":"<<xs.length()<<endl;
    
    
    
    auto xc16_auto = 'uC'; // by default any Character is char32_t
    char16_t xc16 = 'uC';   
    auto xc32 = 'Uc';           /*unlike suffix in integer literals 'u' and 'U' are diffrent in Character literals*/
    //char32_t xc32 = 'Uc';
    auto xcWide = 'Lc';
    //wchar_t xcWide = 'Lc';
    cout<<sizeof(xc16)<<":"<<xc16<<endl;
    cout<<sizeof(xc16_auto)<<":"<<xc16_auto<<endl;
    cout<<sizeof(xc32)<<":"<<xc32<<endl;
    cout<<sizeof(xcWide)<<":"<<xcWide<<endl;
    
    /*for raw string and UTF encoding 
    https://docs.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp?view=vs-2019
    */
    
    /*Special Character OR space sequence 
    These are collection of two or more Character is specfifc order , start from '\'
    for example '\n' is new line symbol, we consider this sequence as Character not as string 
    onternally its represent a single Character as ASCII code, \n or \<code is Octal/Hexadecimal>
    \n or \20 or \x4A
    */
    
    
    
    
    /*string literals*/
    string s = "this "   "is"  "    satendra   " ":";
    cout<<"|"<<s<<"|"<<s.length()<<endl;
    
    string s1 =" line 1  \
    line 2 \
    lin3 ";
    cout<<"|"<<s1<<"|"<<s1.length()<<endl;
    
    /*Special literals*/
    bool    test    =   true,       //set TRUE value                its not c-style  > 0
            test2   =   false;      // set FALSE value              its not c-style  < 0
    int     *ptr    = nullptr;      // set null value to pointer    its not c-style NULL i.e. void*(0)
    
    
       
    return 0;
}

