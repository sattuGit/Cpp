#include<iostream>
using namespace std;
class DemoFriend; // forward declartion 
class DemoFriend_base;

class DemoFriend_base
{
    private:
        int data;
        void setData(int arg){data=arg;}
        friend void synchData(DemoFriend_base&,DemoFriend&);
    
    public:
        DemoFriend_base(int arg=0):data{arg}{}
        int getData(){return data;}
};
class DemoFriend
{
    private:
        int data;
        void increment(){++data;}
    public:
        DemoFriend(int arg=0):data{arg}{}
        int getData(){return data;}
    /*friend function can be decare in either public or private block*/
    friend void accessData(DemoFriend&);
    
    friend void synchData(DemoFriend_base&,DemoFriend&);
};

void accessData(DemoFriend &obj){
    obj.increment();
    ++obj.data;
}
void synchData(DemoFriend_base &base,DemoFriend& source){
    base.setData(source.getData());
}
bool testFriendFun(){
    std::cout << "-------- Testing Friend Function -------" << std::endl;
    DemoFriend obj;
    DemoFriend_base base;
    std::cout << "Data:"<<obj.getData() << std::endl;
    accessData(obj);
    std::cout << "Data:"<<obj.getData() << std::endl;
    std::cout <<"base data:"<<base.getData()  << std::endl;
    synchData(base,obj); //friend function between more thenone class 
    std::cout << "Data:"<<obj.getData() << std::endl;
    std::cout <<"base data:"<<base.getData()  << std::endl;
    
    
    return true;
}

class DemoAccess{
    // default private 
        int counter_; 
        int getCounter(){return counter_;}
    private:
        void setCounter(int counter){counter_=counter;}    
        
    public:
        int size;
        int  getSize(){return size;}
        void setSize(int arg){size=arg;}
        void setCounterPublic(int arg){ setCounter(arg);}
        int getCounterPublic(){return getCounter();}
        
        void setNamePublic(std::string arg){setName(arg);}
        std::string getNamePublic(){getName();}
    protected:
        std::string name_;
        void setName(std::string name){name_=name;}
        std::string  getName(){return name_;}
};

bool testAccessClass(){
    DemoAccess obj;
    
    /*public data and mmember function */
    std::cout << "Size is :"<<obj.getSize()<< std::endl;
    obj.setSize(3);
    std::cout << "Size is :"<<obj.getSize()<< std::endl;
    obj.size = 5; 
    std::cout << "Size is :"<<obj.getSize()<< std::endl;
    
    cout<<"-------------------------------------------------"<<endl;
    /*Private access */
    /* each one is COMPILE_ERROR 
    std::cout << "counter is "<<obj.getCounter() << std::endl; 
    std::cout << "couter is "<<obj.counter_ << std::endl;
    std::cout << "couter is "<<obj.setCounter(8) << std::endl; */
    std::cout << "Counter "<<obj.getCounterPublic() << std::endl;
    obj.setCounterPublic(7);
    std::cout << "Counter "<<obj.getCounterPublic() << std::endl;
    
    cout<<"-------------------------------------------------"<<endl;
    /*protected*/
    /* COMPILE ERROR
    std::cout << "name:"<<obj.name_ << std::endl;
    std::cout << "name:"<<obj.setName("new") << std::endl;
    std::cout << "name:"<<obj.getName()<< std::endl;
    */
    std::cout << "Name is "<<obj.getCounterPublic() << std::endl;
    obj.setNamePublic("UpdateName");
    std::cout << "Name is "<<obj.getCounterPublic() << std::endl;
    
    
    return true;
}