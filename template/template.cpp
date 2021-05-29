/******************************************************************************
The concept of templates can be used in two different ways:

Function Templates
Class Templates

Function Templates:
	source : why we use typename keyword in template 
	https://en.wikipedia.org/wiki/Typename#:~:text=From%20Wikipedia%2C%20the%20free%20encyclopedia,or%20declaration%20is%20a%20type.
	
	https://mariusbancila.ro/blog/2021/03/15/typename-or-class/#:~:text=when%20declaring%20template%20template%20parameters,declaring%20dependent%20types%20use%20typename
	
	https://www.programiz.com/cpp-programming/templates#:~:text=Templates%20are%20powerful%20features%20of,and%20flexibility%20of%20the%20programs.
*******************************************************************************/
#include <iostream>
using namespace std;
#define quote(x) "x"
#include<typeinfo>

/*How to check whether objects belong to same class or not*/
template<typename T1, typename T2>
bool isEqual(T1 arg1,T2 arg2){
    //const type_info& ti1=typeid(arg1).name();
    return typeid(arg1).name() == typeid(arg2).name() ? 1:0;
}

/*are belong to same base class ??*/
template<typename base, typename T>
bool isLowInharitance(const T*){
    return is_base_of<base,T>::value;
}

template<typename T1,typename T2>
bool isSameAsset(T1 arg1,T2 arg2){
    return arg1.value()==arg2.value() ? 1:0;
}

template<typename T>
class tmplateClass
{
        T *var;
        tmplateClass *next;
    public:
        tmplateClass(T arg){
            *(this->var) = arg;
        }
        
        T getData(){return *var;}
        void setData(T arg){*(this->var)=arg;}
};

class tmp{
    int x;
    
    public:
        //structX stobj;
        tmp(int arg=0):x{arg}{}
        int value(){return x;}    
};

class tmp2:tmp{};

class tx{
    int x;
    public:
        tx(int arg=0):x{arg}{}
        int value(){return x;}    
};
int main()
{
    tmp obj1,obj3;
    tmp2 obj2;
    std::cout << quote(obj1)<<typeid(obj1).name() << std::endl;
    if(isEqual(obj1,obj3)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    if(isEqual(obj1,obj2)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    if(isEqual(obj2,obj2)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    cout<<"-------------------------------------------------\n";
    
    if(isLowInharitance<tmp>(&obj1)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    if(isLowInharitance<tmp>(&obj2)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    if(isLowInharitance<tmp>(&obj3)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    if(isLowInharitance<tmp2>(&obj1)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    if(isLowInharitance<tmp2>(&obj2)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    if(isLowInharitance<tmp2>(&obj3)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    cout<<"-------------------------------------------------\n";
    tx obj4;
    if(isSameAsset(obj1,obj4)) cout<<" equal"<<endl; else cout<<"not equal"<<endl;
    cout<<"-------------------------------------------------\n";
    
    tmplateClass<int> node(5);
    cout<<node.getData()<<endl;
    cout<<"-------------x------------------------------------\n";
    return 0;
}
