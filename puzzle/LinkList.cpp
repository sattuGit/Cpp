#include<iostream>
#include "node.h"
using namespace std;




int main(){
   // Node one;
   
   SingleLL ll;
   if(!ll.isEmpty())cout<<ll.getHeadData()<<endl;
   ll.displayList();
   cout<<"=>"<<ll.returnMid()<<std::endl;
   
   ll.addNode(1);
   if(!ll.isEmpty())cout<<ll.getHeadData()<<endl;
   ll.displayList();
cout<<"=>"<<ll.returnMid()<<std::endl;
    ll.addNode(2);
    cout<<"=>"<<ll.returnMid()<<std::endl;
    ll.addNode(3);
    cout<<"=>"<<ll.returnMid()<<std::endl;
    ll.addNode(4);
    cout<<"=>"<<ll.returnMid()<<std::endl;
    ll.addNode(5);
   
   if(!ll.isEmpty())cout<<ll.getHeadData()<<endl;
   ll.displayList();
   
   cout<<"=>"<<ll.returnMid()<<std::endl;
return 0;}
