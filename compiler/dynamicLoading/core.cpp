#include<iostream>
#include<dlfcn.h>
#include "distrubution.hpp"
int main(){
    /*Setup for dynamic loading*/
    void *_handle;      //library pointer 
    std::string _path2lib;          //Object location 
    std::string _allocateSymbol;    //function_name for entry 
    std::string _delSymbol;         // function_name for exit

    /*Open lib */
    //_path2lib= "libdistrubution.so";    //will look into  LD_LIBRARY_PATH
    _path2lib= "./libdistrubution.so"; 
    _handle = dlopen(_path2lib.c_str(),RTLD_NOW|RTLD_LAZY);
    if(!_handle){
        std::cerr <<dlerror()<<std::endl;
        return 0; 
    }else{
        std::cout<<"Object loaded Success..."<<std::endl;
    }

    /*to cathc function we need pointer to function AKA function pointer */
    Arthametic* (*entry)(int);  //Arthametic* getArthametic(int);
    void (*exit)(Arthametic*);  //void delArthametic(Arthametic*);
 
    _allocateSymbol = "getObject";
    _delSymbol      = "delObject";
 
    
    entry =reinterpret_cast<Arthametic* (*)(int)>(dlsym(_handle,_allocateSymbol.c_str()));
    exit  =reinterpret_cast<void (*)(Arthametic*)>(dlsym(_handle,_delSymbol.c_str())) ;
    

    if(!entry || !exit ){
        std::cerr<<"Method not exposed .. in object "<<_allocateSymbol<<"::"<<entry<<", "<<_delSymbol<<"::"<<exit<<std::endl;
        std::cerr<<dlerror()<<std::endl;
        /*close shared object */
        if (dlclose(_handle) != 0) {
			std::cerr << dlerror() << std::endl;
		}
    }else{
        std::cout<<"Method found .. in object "<<_allocateSymbol<<"::"<<entry<<", "<<_delSymbol<<"::"<<exit<<std::endl;
    }
    
    int dll_arg = 1;
    Arthametic *pObj =  (*entry)(dll_arg);
    std::cout<<pObj->getData()<<std::endl;
    pObj->setData(22);
    std::cout<<pObj->getData()<<std::endl;
    (*exit)(pObj); // OR delete pObj;  

    /*Close shared object */
    if (dlclose(_handle) != 0) {
		std::cerr << dlerror() << std::endl;
	}    
    return 0;
}