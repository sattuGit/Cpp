/*
Demo Simple program to demonstrate thread program for C++11 , using std::thread
Author: www.Satendra.info
*/

#include<thread>
#include<iostream>
#include "callableObjectsDemo.h"
//#include "demon.h"

int main(){
    /*lets call from main thread ie sequential order  
    simpleFunction(10);
    Functor fun = 5;
    fun(10);
    lembda_f(10);
    */
    
    /*lets trigger it as thread */
    //syntax std::thread t_object(callableObject,<argument>)

    std::thread thSimFun(simpleFunction,100); //&simpleFunction would better performance 
    
    std::thread thLmabda(lembda_f,100); //or we can write lembda itself 

    /*  TO-DO calling functor in thread */

    std::thread demon([](){static int i =0; while(true){std::cout<<"Demon["<<i++<<"]"<<std::flush; std::this_thread::sleep_for(std::chrono::seconds(1) );}});
    demon.detach(); // we make it free 
    // demon.join();  // make application crash , as demon is detach already 
    
    /* To check any thread is joinable or not*/
    if(demon.joinable()) demon.join(); // which will never true 
    thSimFun.join();        // join is called by main , so main will hold till thSimFun ends 
    thLmabda.join();        // join is called by main , so main will hold till thLmabda ends 
    std::cout<<"thSimFun thLmabda execution is done"<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(100));
    /*make Demon*/
    



    
    return 0;
}