#include<iostream>


class DemoFriend; // forward declartion 
class DemoFriend_base;

class DemoFriend_base
{
    private:
        int data;
        void setData(int arg){data=arg;}
        friend void synchData(DemoFriend_base&,DemoFriend&); //global friend function 
        friend void dummyDisplay(DemoFriend_base&);
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
        void dummyDisplay(DemoFriend_base &baseObj){
            std::cout << "DemoFriend data:"<<this->data;
            /*  TO-DO confirmation  
            this is whay we need friend class 
            std::cout<<"DemoFriend_base data"<< baseObj.data << std::endl;
            */
        }
    friend void synchData(DemoFriend_base&,DemoFriend&);
};
void accessData(DemoFriend &obj){
    obj.increment();
    ++obj.data;
}
void synchData(DemoFriend_base &base,DemoFriend& source){
    base.setData(source.getData());
}
/* Friend class */
class DemoFriendClassBase
{
    private:
        int data;
        void setData(int arg){data=arg;}
    public:
        DemoFriendClassBase(int arg=0):data{arg}{}
        int getData(){return data;}
        
        friend class DemoFriendClass;
};
class DemoFriendClass
{
    private:
        int data;
    public:
        DemoFriendClass(int arg=0):data{arg}{}
        int getData(){return data;}
        void setData(int arg){data=arg;}
        void setDataSynch(int arg,DemoFriendClassBase &base){
            setData(arg);
            base.setData(arg);
        }
};


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
    obj.dummyDisplay(base);
    std::cout << "------- friend class ---------" << std::endl;   
    DemoFriendClassBase fbObj;
    DemoFriendClass     fObj;
    std::cout << "BaseY: "<<fbObj.getData() <<" front :"<<fObj.getData()<< std::endl;
    fObj.setData(5);
    std::cout << "Base:"<<fbObj.getData() <<" front :"<<fObj.getData()<< std::endl;
    fObj.setDataSynch(6,fbObj);
    std::cout << "Base:"<<fbObj.getData() <<" front :"<<fObj.getData()<< std::endl;
    return true;
}
