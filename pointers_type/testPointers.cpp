#include<iostream>
#include<memory>
#include "pointers.h"
bool testWeekPointer(){
    std::cout<<"testWeekPointer"<<std::endl;    
    std::shared_ptr<Demo> p0 =  std::make_shared<Demo>(5);
    std::shared_ptr<Demo> p1 =p0;
    std::cout<<"Count :: "<<p1.use_count()<<std::endl;
    std::weak_ptr<Demo> pw0,pw1;
    pw0 = p0;
    std::cout<<"Count :: "<<p0.use_count()<<std::endl;
    //.expired ie.  check refcount ==0 
    if(!pw0.expired())std::cout<<" Memory is valid "<<std::endl;
    pw1= pw0.lock();
    std::cout<<"Count :: "<<p1.use_count()<<std::endl;
return true;
}
bool testAutoPointer(){

return true;
}


bool testSharePointer(){
    std::cout<<"testSharePointer"<<std::endl;    
    {  //BLOCK A
        std::cout<<"testSharePointer:: BLOCK A"<<std::endl;    
        /*One way to create shared_ptr from raw pointer 
            But not the recommended one as application have one copy of raw address 
            which may cause of accidential free , on that case shared pointer become currupt (dangling)
        Alwys use std::shared_ptr<T> pName(new <T>());
        */ 
        
        Demo *pDemoRaw = new Demo();
        std::shared_ptr<Demo> p_1(pDemoRaw); 
        std::cout<<"Raw pointer is going to delete  "<<std::endl;
        //delete pDemoRaw; // this line leads to runtime error , double free 
        std::cout<<"Declartion is DONE "<<std::endl;
    }
    
    {//BLOCK B
    std::cout<<"testSharePointer:: BLOCK B"<<std::endl;    
    std::shared_ptr<Demo> p1 (new Demo(22));
    std::shared_ptr<Demo> _p1 = std::make_shared<Demo>(23);  //another way to create 
    std::shared_ptr<Demo> p2 ;
    if(!p2.unique()) std::cout<<"Empty share pointer is not unique"<<std::endl;
    if(p1.unique()) std::cout<<"share pointer with ref count 1 , return true for unique "<<std::endl;

    
    std::cout<<"ref count for p1:"<<p1.use_count()<<std::endl;
    p2=p1; //assignment opertor will update ref count, (note for unique_ptr its error) 
    if(!p1.unique()) std::cout<<"share pointer with ref count >1 , return false for unique "<<std::endl;
    std::cout<<"ref count for p2:"<<p2.use_count()<<std::endl;
    std::shared_ptr<Demo> p3(p1);
    std::cout<<"ref count for p1:"<<p1.use_count()<<std::endl;
    p1.reset(); // P1 reset it self i.e p1 is relesing row pointer , which lead count to be decrease 
    std::cout<<"ref count for p2:"<<p2.use_count()<<std::endl;
    Demo *tmp  = p2.get();  // return raw pointer 
    std::cout<<tmp->getData()<<std::endl;
    }

    {
        //swap 
        std::shared_ptr<Demo> p1 = std::make_shared<Demo>(1);
        std::shared_ptr<Demo> p2 = std::make_shared<Demo>(2);
        std::cout<<p1->getData()<<std::endl;
        std::cout<<p2->getData()<<std::endl;
        p1.swap(p2);
        std::cout<<p1->getData()<<std::endl;
        std::cout<<p2->getData()<<std::endl;
    }

    return true;
}

bool testUniquePointer(){
    // Ref : https://thispointer.com/c11-unique_ptr-tutorial-and-examples/
    https://isocpp.org/blog/2019/06/quick-q-differences-between-stdmake-unique-and-stdunique-ptr-with-new
    std::cout << "::testUniquePointer::" << std::endl;
    
    /* difficulties in raw pointer */
    { /* block A*/
    Demo *p = new Demo();
    Demo *q = p;
    std::cout<<p->getData()<<std::endl;
    p->setData(6);
    if (q->getData() != 6) return false ;
    // if devloper miss below line , its lead to mmeory leak , if delete p and q both will lead runtime error 
    delete p; 
    }

    { /*code block B*/   
    // How to create unique pointer 
    
    //fist style  using temporary object i.e. copy const 
    std::unique_ptr<Demo> p1  (new Demo());
    
    //2nd style getting access from other unique 
    std::unique_ptr<Demo> p2;
    //p2=p1;  // Error assignment
    
    if(p1){   // OR if(p1!==nullptr)  //checking whether unique pointer is not empty  
        p2 = move(p1 );  // p1 is loosing its ownership and giving it to p2;
    }
    
    
    //3rd  from Raw pointer ### not recommended 
    Demo *p3Raw = new Demo();
    std::unique_ptr<Demo> p3(p3Raw);

    // 4th best way , from make unique 
    std::unique_ptr<Demo> p4 = std::make_unique<Demo>(); 
    std::unique_ptr<Demo> p5 = std::make_unique<Demo>(5); 
    
    //what will not work 
    /*
    compile error 
    Demo *p_2 =  p1;  
    std::unique_ptr<Demo> p2x = p1;  
    p2x=p1; //error 
    std::unique_ptr<Demo> p2x = new Demo();
    */   
    }

    { // how to make copy of unique pointer // cheet code, should not use
        Demo *tmp = new Demo(66);
        std::cout<<"Address of object raw, pointing by tmp"<<tmp<<std::endl;
        
        std::unique_ptr<Demo> pUtmp (tmp);
        
        std::cout<<"Address of pUtmp"<<std::addressof (pUtmp)<<std::endl;
        std::cout<<"Address of pUtmp"<<std::addressof (*pUtmp)<<std::endl;
        
        Demo *proxyTmp = std::addressof(*pUtmp);  //workaround way 
        Demo *proxyTmp2 = pUtmp.get();             // method given by pointer itself 
        std::cout<<"Address of proxyTmp   ::"<<std::addressof (proxyTmp)<<std::endl;
        std::cout<<"Address of *proxyTmp  ::"<<std::addressof (*proxyTmp)<<std::endl;
        std::cout<<"Address of proxyTmp2  ::"<<std::addressof (proxyTmp2)<<std::endl;
        std::cout<<"Address of *proxyTmp2 ::"<<std::addressof (*proxyTmp2)<<std::endl;
        proxyTmp->setData(88);
        std::cout<<tmp->getData()<<std::endl;
    }
    
    
    {  // BLOCK C
    std::cout << "::testUniquePointer::BLOCK C" << std::endl;
    
    std::unique_ptr<Demo> p1  (new Demo());    
    std::unique_ptr<Demo> p2;
    
    if(p1) {std::cout<<" p1 is holding row address "<<std::endl; }else{std::cout<<" p1 is empty "<<std::endl;}
    if(p2) {std::cout<<" p2 is holding row address "<<std::endl; }else{std::cout<<" p2 is empty "<<std::endl;}
    
    std::cout<<p1->getData()<<std::endl;
    p1->setData(88);
    if(p1)p2 = move(p1);
    
    if(p1) {std::cout<<" p1 is holding row address "<<std::endl; }else{std::cout<<" p1 is empty "<<std::endl;}
    if(p2) {std::cout<<" p2 is holding row address "<<std::endl; }else{std::cout<<" p2 is empty "<<std::endl;}
    
    std::cout<<p2->getData()<<std::endl;
    }
    
    {
    std::cout << "::testUniquePointer::BLOCK D" << std::endl;    
    
    std::unique_ptr<Demo> p0(new Demo(555));
    std::cout<<p0->getData()<<std::endl;
    Demo *t = p0.release();  // it will return raw pointer , and it self empty unique pointer 
    std::cout<<t->getData()<<std::endl;
    delete t;   // now irs dewvloper responsibility 
    
    /*resuing */
    p0.reset(new Demo(101));
    std::cout<<p0->getData()<<std::endl;
    p0.reset(); // it will delete pointed memory , make it empty 
    std::cout<<"------------------------"<<std::endl;
    }  
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