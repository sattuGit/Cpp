#include<iostream>
#include"DPF.h"
bool testFactoryDP(){
 Cook cook ;    
    Domnio dm;
    cook.createPizz(&dm);
    cook.display();
    
    std::cout << "------------------" << std::endl;
  // Cook cook ;    
    PapaJ pj;
    cook.createPizz(&pj);
    cook.display();    

    return true;
}