#include<iostream>
#include<memory>
#include "pointers.h"
bool testSharePointer(){
    std::shared_ptr<Demo> p1 (new Demo());
    //std::shared_prt<Demo> p2(p1); compile error
    std::shared_ptr<Demo> p2;
    std::cout<<"ref count for p1:"<<p1.use_count()<<std::endl;
    p2=p1;
    std::cout<<"ref count for p2:"<<p2.use_count()<<std::endl;
    p1.reset();
    std::cout<<"ref count for p2:"<<p2.use_count()<<std::endl;
    return true;
}

bool testUniquePointer(){
    // Ref : https://thispointer.com/c11-unique_ptr-tutorial-and-examples/
    std::cout << "::testUniquePointer::" << std::endl;
    Demo *p = new Demo();
    Demo *q = p;
    std::cout<<p->getData()<<std::endl;
    p->setData(6);
    if (q->getData() != 6) return false ;
 
    {   
    std::unique_ptr<Demo> p1  (new Demo());
    /*compile error 
    Demo *p2 =  p1;  
    std::unique_ptr<Demo> p2 = p1;  
    std::unique_ptr<Demo> p2 (new Demo());
    */
    std::cout<<"Address of p1 "<<std::addressof (p1)<<std::endl;
    std::cout<<p1->getData()<<std::endl;
    std::unique_ptr<Demo> p2;
    std::cout<<"Address of p2 "<<std::addressof (p2)<<std::endl;
    if(p1) {std::cout<<" p1 is holding row address "<<std::endl; }else{std::cout<<" p1 is empty "<<std::endl;}
    if(p2) {std::cout<<" p2 is holding row address "<<std::endl; }else{std::cout<<" p2 is empty "<<std::endl;}
    p2 = move(p1);
    //we can also check p1==nullptr 
    if(p1) {std::cout<<" p1 is holding row address "<<std::endl; }else{std::cout<<" p1 is empty "<<std::endl;}
    if(p2) {std::cout<<" p2 is holding row address "<<std::endl; }else{std::cout<<" p2 is empty "<<std::endl;}
    std::cout<<"Address of p2 "<<std::addressof (p2)<<std::endl;
    std::cout<<p2->getData()<<std::endl;
    } /*this is the end of scope and memory will free automaticly  */

    std::unique_ptr<Demo> p4(new Demo());
    p4.reset(); // it will delete pointed memory , make it empty 

    std::unique_ptr<Demo> p5(new Demo());
    Demo *pP5 = p5.release(); // release raw pointer , become empty but memory won't delete 
    //pP5 will cause of memory leak 
    std::cout<<"------------------------"<<std::endl;
    return true;
}


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