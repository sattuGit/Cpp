#include<iostream>
using namespace std;
class SimpleDerive;class SimpleBase{
    //default private 
    int data;
    
    public:
        int pubData;
        
        SimpleBase(int arg=0){
            std::cout << "SimpleBase construtor "<<arg << std::endl;
            data=arg;
            pubData=arg;
        }
    protected:
};

class SimpleDerive:public SimpleBase
{
    int data2;
    
    public:
    /*
        void display(){
            std::cout << "Driven class display method " << std::endl;
            //std::cout << pubData << std::endl;
        }
    */    
        SimpleDerive(int argBase, int argDerive):SimpleBase{argBase}{
            std::cout << "SimpleDerive construtor "<<argDerive << std::endl;
            data2=argDerive;
        }
};
/*
void SimpleDerive::display()
{
    std::cout << "Driven class display method " << std::endl;
    std::cout << pubData << std::endl;
}*/


