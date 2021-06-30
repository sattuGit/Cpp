#include "SingleLL.h"
bool testMidNodeLinkList(){
   SingleLL ll;
   if(!ll.isEmpty())std::cout<<ll.getHeadData()<<std::endl;
   ll.displayList();
   std::cout<<"=>"<<ll.returnMid()<<std::endl;
   
   ll.addNode(1);
   if(!ll.isEmpty())std::cout<<ll.getHeadData()<<std::endl;
   ll.displayList();
   std::cout<<"=>"<<ll.returnMid()<<std::endl;
   ll.addNode(2);
   std::cout<<"=>"<<ll.returnMid()<<std::endl;
   ll.addNode(3);
   std::cout<<"=>"<<ll.returnMid()<<std::endl;
   ll.addNode(4);
   std::cout<<"=>"<<ll.returnMid()<<std::endl;
   ll.addNode(5);
   
   if(!ll.isEmpty())std::cout<<ll.getHeadData()<<std::endl;
   ll.displayList();
   
   std::cout<<"=>"<<ll.returnMid()<<std::endl;

return true ;
}
