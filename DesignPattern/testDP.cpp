#include<iostream>
#include<pthread.h> 
#include"DPF.h"
#include"SINGLE.h"

void* getObject(void *threadID){
    SingletonTS *pSingle = SingletonTS::getInstance();
    long p = reinterpret_cast<long>(threadID);
    std::cout<<"Count is "<<p<<"|"<< pSingle->getPoolCount()<<","<<pSingle->getPoolSize()<<std::endl;    
}
bool testSingletonThreadSafe()
{
    short int MAX = 100;
    pthread_t threads[MAX];
    int rc;
    for(int i =0;i<MAX;++i){
        std::cout<<"Thread Creation start["<<i<<"]"<<std::endl;
        rc = pthread_create(&threads[i],NULL,getObject,(void*)i);
        if(rc){
            std::cout<<"Thread Creation Failed"<<std::endl;
            return false;
        }
    }
    pthread_exit(NULL);
    return true;
}

bool testSingletonDP(){
    std::cout << "-------------------------------" << std::endl;
    Singleton* obj1 = Singleton::getInstance();
    std::cout << "Pool Size : "<<Singleton::getPoolSize() << std::endl;
    std::cout << "Object Variable "<<obj1->getPoolCount() << std::endl;
    
    
    Singleton* obj2 = Singleton::getInstance();
    std::cout << "Pool Size : "<<Singleton::getPoolSize() << std::endl;
    std::cout << "Object Variable "<<obj2->getPoolCount() << std::endl;
    
    std::cout << "Address of obj1:"<<std::addressof(obj1)<<"|"<<&(*obj1) << std::endl;
    std::cout << "Address of obj2:"<<std::addressof(obj2)<<"|"<<&(*obj2 )<< std::endl;
    delete obj1;
    std::cout << "-------------------------------" << std::endl;
    /*Test Copy const bug 
    Singleton cpObj = *obj1;
    std::cout << "Pool Size : "<<Singleton::getPoolSize() << std::endl;
    std::cout << "Address of cpObj:"<<std::addressof(cpObj)<<"|"<<&(cpObj )<< std::endl;
    std::cout << "Object Variable "<<obj1->getPoolCount() << std::endl;
    std::cout << "Object Variable "<<cpObj.getPoolCount() << std::endl;
    std::cout << "-------------------------------" << std::endl; */
    /*Test assignment 
    Singleton *t  = (Singleton*)operator new(sizeof(Singleton));
    std::cout << "Pool Size : "<<Singleton::getPoolSize() << std::endl;
    std::cout << "Object Variable "<<t->getPoolCount() << std::endl;
    std::cout << "Address of tmp:"<<std::addressof(t)<<"|"<<&(*t )<< std::endl;
    *t=cpObj;
    std::cout << "Pool Size : "<<Singleton::getPoolSize() << std::endl;
    std::cout << "Address of tmp:"<<std::addressof(t)<<"|"<<&(*t )<< std::endl;
    std::cout << "Object Variable "<<t->getPoolCount() << std::endl;
    */
    return true;
}

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