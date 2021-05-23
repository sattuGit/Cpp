#ifndef _CONSTRUCT_HPP
#define _CONSTRUCT_HPP
#include<iostream>
using namespace std;
/*This is to demo copy constructor (deep copy and shallow copy*/
class defaultCopyConst{
    int count;
    int* data;
  public:
    int getCount(){return count;}
    void setCount(int cnt){count=cnt;}
    int getData(){return *data;}
    void setData(int cnt){*data=cnt;}
    defaultCopyConst(int argData=0):count{argData}{ /*as this will act as default copy constructure as well*/
      data = new int(argData);
    }
    void display();
};

class deepCopyConst{
    int count;
    int* data;
  public:
    int getCount(){return count;}
    void setCount(int cnt){count=cnt;}
    int getData(){return *data;}
    void setData(int cnt){*data=cnt;}
    deepCopyConst(int argData=0):count{argData}{ /*as this will act as default copy constructure as well*/
      data = new int(argData);
    }
    deepCopyConst(deepCopyConst &arg){
      count=arg.count;
      data= new int(arg.getData());
    }
    void display();
};

class ConstDemo{
    public:
        int data;
        ConstDemo(int x){
            if(isValid())data=x;
        }
        int getData(){return data;}
    private :
    bool isValid(){std::cout<<"called"<<endl;return true ;}
};

class demoClass{
    public:
    demoClass():i{10},j{20}{}
    void dis(){
        cout<<"["<<i<<"]["<<j<<"]"<<endl;
    }
    private :
    int i;
    int j;
};
class ClassWithDefaut{
    int x;
    int y;
    public:
    ClassWithDefaut(int x_=0,int y_=0):x{x_},y{y_}{}
    ClassWithDefaut(){}
    ClassWithDefaut(const ClassWithDefaut &obj){ x= obj.x;y=obj.y+1;}
    void display(){
        cout<<"["<<x<<"]["<<y<<"]"<<endl;
    }
};


class RVODemo{
    int x,y;
    public:
    RVODemo(const RVODemo&& obj){cout<<"constructure called "<<endl;x=obj.x;y=obj.y;}
    RVODemo(int x){x=x;y=x;}

    void set(){x=10;y=20;}
    void display(){
        cout<<"["<<x<<","<<y<<"]"<<endl;
    }
};
/*
RVODemo makeObject(){
    RVODemo p(8);// = new  RVODemo();
    p.display();
    return p;
}
*/
class A{
  int *ptr;
public:
  A(){
    // Default constructor
    cout << "Calling Default constructor\n";
    ptr = new int ;
  }

  A( const A && obj){
    // Copy Constructor
    // copy of object is created
    this->ptr = new int;
    // Deep copying
    cout << "Calling Copy constructor\n";
  }

  ~A(){
    // Destructor
    cout << "Calling Destructor\n";
    delete ptr;
  }

};

#endif