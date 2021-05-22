#include<iostream>
#include "constructure.hpp"
#include <vector>
//https://www.geeksforgeeks.org/constructors-c/
using namespace std;
int main()
{
    /*can we call method from constructure*/
    ConstDemo obj1= 8;
    cout<<"----"<<obj1.getData()<<endl;

    demoClass obj2;
    obj2.dis();


    ClassWithDefaut x(1);
    ClassWithDefaut y = x;
    ClassWithDefaut z(y);
    x.display();
    y.display();
    z.display();

    RVODemo rovBase = makeObject();
    //rovBase.set();
    rovBase.display();

    vector <A> vec;
  vec.push_back(A());
  cout<<"-----------"<<endl;
    return 0;
}