#include<iostream>
#include "constructure.hpp"
#include <vector>
//https://www.geeksforgeeks.org/constructors-c/
using namespace std;
int main()
{
  /*copy construture
  :shallow copy vs deep copy:
    is copying memebers to members (copy whole structure using memcopy)
    in general assignement operator as well using shallow copy as default (similer to copy)
    first we reproduce the proble of shallow copy*/
  
  defaultCopyConst obj2(2);
  obj2.display(); //22

  defaultCopyConst obj3(obj2);  //copy consstructure 
  obj3.display(); //shellow copy default 22

  obj2.setData(5); 
  obj2.setCount(5);
  obj2.display(); //55
  obj3.display();
  cout<<"-------------------"<<endl;
  deepCopyConst x1(2);
  deepCopyConst x2(x1);
  x1.display();
  x2.display();
  x1.setCount(3);
  x1.setData(3);
  x1.display();
  x2.display();
  

    /*can we call method from constructure
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
  cout<<"-----------"<<endl;*/
    return 0;
}