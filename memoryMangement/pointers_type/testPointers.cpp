#include<iostream>
#include "pointers.h"
bool testSmartPointer(){
    std::cout << "::testSmartPointer::" << std::endl;
    /*Simple pointer /raw ointer */
    for(auto i=0;true && i<10;++i) {
        std::cout << "------------------------" << std::endl;
        Demo *t = new Demo();
        std::cout << t->getData() << std::endl;
        t->setData(i);
        std::cout << t->getData() << std::endl;
    }
    std::cout << "=============================" << std::endl;
    /*Smart pointer */
    for(int i=0;i<10;++i) {
        std::cout << "------------------------" << std::endl;
        DemoSmart t(new Demo()); 
        std::cout << t->getData() << std::endl;
        t->setData(i);    
        std::cout << t->getData() << std::endl;
    
    }
    std::cout << "=============================" << std::endl;
    /*Generic smart pointer (template)*/
    for(int i=0;i<10;++i) {
        std::cout << "------------------------" << std::endl;
        SmartPtr<Demo> t(new Demo()); 
        std::cout << t->getData() << std::endl;
        t->setData(i);    
        std::cout << t->getData() << std::endl;
    }
    
    return true;
}