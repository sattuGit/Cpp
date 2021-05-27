#include<iostream>
#include "constructure.hpp"
using namespace std;
class defaultCopyConst;
class deepCopyConst;
void defaultCopyConst::display()
{
    cout<<"count:"<<count<<" datais:"<<*data<<endl;
}
void deepCopyConst::display()
{
    cout<<"count: "<<count<<" datais:"<<*data<<endl;
}

