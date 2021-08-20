#ifndef __SATTU_CUSTOMOBJ_STL_POC_
#define __SATTU_CUSTOMOBJ_STL_POC_
class Person{
    private :
        std::string _name;
        size_t _jobID;
        int *_pData;
    public:
        /*Default constructor and parametrized constructor */
       Person(std::string argName="<NULL>",size_t argJobid = 0, int argData=0):_name{argName},_jobID{argJobid}{
           _pData = new (std::nothrow) int(argData);
           std::cout<<"Person Constructor called"<<std::flush<<std::endl;
       }
       /*Destructor*/
       virtual ~Person(){
           delete _pData;
           std::cout << "Person Distruction " << std::endl;
       }
       /*Copy constructor */
       Person( const Person& argObj) {
           std::cout << "Copy Constructor called " << std::endl;
           _name = argObj.getName();
           _jobID= argObj.getJobID();
           _pData = new (std::nothrow) int(argObj.getData());
       }
       /*Assignment overloading to avoid shellow copy */
       void operator = (const Person &argObj){
            std::cout << "Assignment operator overloading" << std::endl;
            _name = argObj.getName();
            _jobID= argObj.getJobID();
            _pData= new (std::nothrow) int(argObj.getData());
       }
       
       bool operator < (const Person &a){
           return _name>a.getName() ? true :false;
       }
       
       std::string getName()const {return _name;}
       size_t getJobID()const {return _jobID;}
       int getData()const {return *_pData;}
       
       void setName(const std::string _argName){_name=_argName;}
};

#endif