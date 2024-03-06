#include<iostream>
#include<cstring>
class DefaultClass{
    public:
        int _data;
        int *_pData;
    
       /*
        DefaultClass(){}
       */ 
       DefaultClass():_data{0},_pData{nullptr}{
           std::cout << "Default constructor" << std::endl;
       }
       
       //user defined , not available by default 
       DefaultClass(const int &argData):_data{argData},_pData{nullptr}{
           std::cout << "Default Argumented constructor" << std::endl;
           if(argData<1){
               _data=0;
           }else{
              _pData = new (std::nothrow) int[_data];
              memset(_pData,0,_data);
            }                 
       }
       
       /*DefaultClass(const DefaultClass &argObj){
         memcpy(this,std::addressof(argObj),sizeof(argObj));  
       }*/
       DefaultClass(const DefaultClass &argObj){
           std::cout << "Copy constructor" << std::endl;
           this->_data = argObj._data;
           this->_pData = new (std::nothrow) int[_data];
           if(this->_pData!=nullptr)memcpy(this->_pData,argObj._pData,_data);
       }
       
       /*DefaultClass& operator=(const DefaultClass &rvalObj){
           if(this==std::addressof(rvalObj)) return *this;
           memcpy(this,std::addressof(rvalObj),sizeof(rvalObj));
           return *this;
       }*/
       DefaultClass& operator=(const DefaultClass &rvalObj){
           std::cout << "operator Assignment" << std::endl;
           if(this==&rvalObj) return *this;
           this->_data=rvalObj._data;
           
           if(_pData) delete []_pData;
           
           this->_pData=new (std::nothrow) int[_data];
           if(_pData!=nullptr) memcpy(this->_pData,rvalObj._pData,_data);
           return *this;
       }
       
       /*~DefaultClass(){}*/
       virtual ~DefaultClass(){
           std::cout << " Distructor" << std::endl;
           delete []_pData; 
       }
       
       // C++11 onward 
       DefaultClass(DefaultClass&& argObj){
           std::cout << "move copy  constructor" << std::endl;
            this->_data = argObj._data;
            this->_pData = argObj._pData;
            argObj._data=0;
            argObj._pData=nullptr;
       }
       // C++11 onward 
       DefaultClass& operator =(DefaultClass &&argObj){
           std::cout << "move Assignment" << std::endl;
           if(this==std::addressof(argObj)) return *this;
           this->_data = argObj._data;
           this->_pData= argObj._pData;
            argObj._data=0;
            argObj._pData=nullptr;
            return *this ;
       }
       
       //  DefaultClass()=delete ;  DefaultClass a;  will throw error ,delete compiler generated default constructor    
       //  DefaultClass()=default ;  // use compiler genrated default constructor 
};

int main(){
    int i=10;
    DefaultClass a;
    DefaultClass b(10);
    a=b;
    DefaultClass c(std::move(10));
    std::cout << a._pData<<"|"<<b._pData << std::endl;
    return EXIT_SUCCESS;
}