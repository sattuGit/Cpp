#ifndef __DP_SINGLE_
#define __DP_SINGLE_
#include "../compiler/compilerMacro.h"
#include<iostream>
#include<pthread.h>
#include<mutex>

class Singleton{
    private:
        Singleton():_objectCount{0}{std::cout << "construtor" << std::endl;} //private construtor will prevent direct object creation 
        static Singleton* _instance;
        static size_t _max;
        size_t _objectCount; //object level varibale 
    public:
        ~Singleton(){std::cout << "Distructor" << std::endl;_max=0;if(!_instance)delete _instance; _instance=nullptr;}
        static Singleton* getInstance(){
            if(_max>10){return nullptr;}
            if(!_instance){
                _instance = new Singleton();
            }
            ++_max;
            return _instance;
        }
        static size_t getPoolSize(){return _max;}
        size_t getPoolCount(){++_objectCount;return _objectCount;}
        /*C++11 ways to prevent copy and assignment object creation, it will delete compiler genrated methods*/
        Singleton(const Singleton&) = delete;
        Singleton& operator = (const Singleton&) = delete;
    private:
        /*C++ old way to prevent copy construtor and assignment operator for creating object , make them private*/
        //Singleton(const Singleton &object){};
        //Singleton& operator = (const Singleton &object){};
};
Singleton* Singleton::_instance=nullptr; //initialization 
size_t Singleton::_max = 0;


class SingletonTS{
    private:
        SingletonTS():_objectCount{0}{std::cout << "\nconstrutor "<<_objectCount<<","<<_max << std::endl;} //private construtor will prevent direct object creation 
        static SingletonTS* _instance;
        static size_t _max;
        size_t _objectCount; //object level varibale
        static std::mutex _m;   
        
    public:
        static bool delInstence(){
            if(!_instance){
                std::unique_lock<std::mutex> lock(_m); // get lock on this line 
                if(!_instance){
                    delete _instance; 
                    SingletonTS::_max=0;
                    SingletonTS::_instance=nullptr;
                    return true ;
                }
            }
            return false;
        }
        ~SingletonTS(){std::cout << "Distructor" << std::endl;}
        static SingletonTS* getInstance(){
            if(_max>100){return nullptr;}
            if(!_instance){
                /*double check to avoid everytime lock overhead and deadlock */
                std::unique_lock<std::mutex> lock(_m); // get lock on this line 
                if(!_instance){
                    _instance = new SingletonTS();
                }
            }
            ++_max;
            return _instance;
        }
        static size_t getPoolSize(){return _max;}
        size_t getPoolCount(){++_objectCount;return _objectCount;}
        /*C++11 ways to prevent copy and assignment object creation, it will delete compiler genrated methods*/
        SingletonTS(const SingletonTS&) = delete;
        SingletonTS& operator = (const SingletonTS&) = delete;   
};
SingletonTS* SingletonTS::_instance=nullptr; //initialization 
size_t SingletonTS::_max = 0; 
std::mutex SingletonTS::_m;
#endif