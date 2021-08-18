/*
Simple program for demonstrate for_each (its algorithem under C++ STL) 
*/
#include<iostream>
#include<vector>
#include<algorithm>

/*
demo , how to access outside varibale 
syntext of lembada
    []()mutable exception ->return {}

[]
capture clause (Also known as the lambda-introducer in the C++ specification.)
    It specifies which variables are captured, and whether the capture is by value or by reference.
    []  => no varibale from outside 
    [&capVar] captures by reference
    [&] captures all variables used in the lambda by reference
    [=] captures all variables used in the lambda by value
    [&, capVar] captures variables like with [&], but capVar by value
    [=, &capVar] captures variables like with [=], but capVar by reference

()
Argument 
    () no Argument
    (int x)  x as value 
    (int &x) x as reference
    (int x,int &y) x as value y as reference

mutable
*/

int main(){
    
    //Named lembada function 
    int _data=1;
    std::vector<int> v;
    for(auto i = 0;i<10;v.push_back(++i));
    
    std::cout << "Value of _data Before:"<<_data << std::endl;
    std::for_each(v.begin(),v.end(),[_data](int &_arg){_arg =_data;});
    std::cout << "Value of _data After :"<<_data << std::endl;
    
    
    /* why we need mutable to modify value 
            The generated operator() is const by default, 
    with the implication that captures will be const when you access them by default. 
    This has the effect that each call with the same input would produce the same result,
    however you can mark the lambda as mutable to request that the operator() that is produced is not const.
    */
    std::cout << "Value of _data Before:"<<_data << std::endl;
    std::for_each(v.begin(),v.end(),[_data](int &_arg)mutable{_data+=_arg;});
    std::cout << "Value of _data After :"<<_data << std::endl;
    
    std::cout << "Value of _data Before:"<<_data << std::endl;
    std::for_each(v.begin(),v.end(),[&_data](int &_arg)mutable{_data+=_arg;});
    std::cout << "Value of _data After :"<<_data << std::endl;
    
    
    return 0;
}