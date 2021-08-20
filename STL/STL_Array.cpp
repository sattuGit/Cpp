#include<iostream>
#include<array> // for STL ARRAY 
#include<algorithm> // for sort 
#include<string>
#include "customObj.h"



int main(){
    {
        /*Declare array */
        std::array<int, 5> arrInt =  {1,2}; 
    
        std::array<int, 5> arrInt2;
        arrInt2 = {1,2,3,4,5};  
    
        //std::array arr3{1,2,3,4,5}; work with C++17 onward only  omit both only <type,size>, one ommit will be be error 
    
        
        /* size or capacity */
        std::cout<<arrInt.size()<<std::endl;
        //checkDecay(arrInt);
    
        /*Read*/
        std::cout<<arrInt[1]<<std::endl;    
        std::cout<<arrInt[5]<<std::endl;        // return garbage 
    
        std::cout<<arrInt.at(1)<<std::endl;
        try{
            std::cout<<arrInt.at(5)<<std::endl;    // throw out of bound error 
        }catch(std::out_of_range &e){
            std::cout<<e.what()<<std::flush<<std::endl;
        }
        
        /*Update */
        arrInt[2]=3;
        arrInt.at(2)=9;

        /*loop*/
        for(auto &it:arrInt){
            std::cout << "[" << it << "]" ;
        }std::cout<< std::endl;
    
        std::for_each(arrInt.begin(),arrInt.end(),[](int &i)->void{++i;});
        
        for (int i = 0; i < arrInt.size(); ++i) {
            std::cout << "[" << arrInt[i] << "]" ;
        }std::cout<< std::endl;
    
        
        /*Algorithm*/
        
        // Assending order sort 
        std::sort(arrInt.begin(),arrInt.end());
        for(auto &it:arrInt){
            std::cout << "[" << it << "]" ;
        }std::cout<< std::endl;
        
        // Desending order sort 
        std::sort(arrInt.rbegin(),arrInt.rend());
        for(auto &it:arrInt){
            std::cout << "[" << it << "]" ;
        }std::cout<< std::endl;
    
        
    }
    std::cout << "--------------- Custom test start from here -----------------------" << std::endl;
    /*Custom objects with std::array*/
    {
        std::array<Person, 5> personList0;  // create 5 oject with default 
        std::array<Person, 5> personList={Person("one",1,1),Person("two",2,2),
                                            Person("Three",3,3),Person("four",4,4),Person("five",5,5)
        };

        std::for_each(personList0.begin(),personList0.end(),[](Person &o)->void{std::cout << o.getName() ;});
        std::cout<<std::flush<<std::endl;
        
        std::for_each(personList.begin(),personList.end(),[](Person &o)->void{std::cout << o.getName() ;});
        std::cout<<std::flush<<std::endl;
        
        std::cout << " Create and display : done " << std::endl;
        for (int i = 0; i < personList0.size(); ++i) {
            personList0[i].setName(std::to_string(i));
        }
        std::cout << "person0 is updated :: done " << std::endl;
        personList0.at(0).setName("Zero");
        for(auto &it:personList0){
            std::cout << "[" << it.getName()<<"]";
        }std::cout<< std::endl;
        
        std::cout << " -------------------sorting start ----------" << std::endl;
        std::sort(personList.begin(),personList.end(),[](Person &a,Person &b)->bool{return a.getName()<b.getName()?true:false;}); /*throw error 
        /* for custom object (non primitive type)
        compare function require require  x<y ? true : false  function 
        option A: provide compare function 
        option B: overload Compare function in class itself */
        
        for(auto &it:personList){
            std::cout << "[" << it.getName()<<"]";
        }std::cout<< std::endl;
        
    }
    
    return EXIT_SUCCESS;
}