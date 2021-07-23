#include<iostream>
#include "distrubution.hpp"
Arthametic* getArthametic(int arg){
    return new Arthametic(arg);
}
void delArthametic(Arthametic* arg){
    delete arg;
    return;
}

extern "C" {
    Arthametic* getObject(int _arg){
        std::cout<<"Inside Object::getObject"<<std::endl;
        return getArthametic(_arg);
    }
    void delObject(Arthametic *done){
        std::cout<<"Inside Object::delObject"<<std::endl;
        delArthametic(done);
    }
}