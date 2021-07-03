#ifndef __POINTERS_
#define __POINTERS_
/*Simple class*/
class Demo{
        public:
            Demo(){std::cout << "Constructor :: Demo" << std::endl;}
            ~Demo(){std::cout << "Distructor :: Demo" << std::endl;}
            int getData(){return x;}
            void setData(int arg){x=arg;}
        private:
            int x ;
};

/*Below class object will act as smart pointer for Demo*/
class DemoSmart{
    private :
        Demo *_ptr;
    public:
        DemoSmart():_ptr{nullptr}{} //intilize Demo pointer 
        ~DemoSmart(){if(_ptr)delete _ptr;} // free demo object once smart pointer die 
        DemoSmart( Demo* arg){ _ptr=arg;}   // accept Demo address as argument while creating object 
        DemoSmart(const DemoSmart&)=delete;     // block copy 
        DemoSmart& operator=(const DemoSmart&)=delete;  //block assignement 
        
        Demo* operator ->(){
            return _ptr;
        }
};

/*Generic smart pointer */
template <class T>
class SmartPtr{
    T *_ptr;
    public:
       SmartPtr():_ptr{nullptr}{}
       ~SmartPtr(){if(_ptr)delete _ptr;}
       SmartPtr(T* arg){_ptr=arg;}
       SmartPtr(const SmartPtr&)=delete;
       SmartPtr& operator=(const SmartPtr&)=delete;
       T* operator->(){return _ptr;}
};
#endif 