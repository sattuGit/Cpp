#ifndef __SATTU_MEMPOOL__
#define __SATTU_MEMPOOL__
#include<iostream>
#include<cstring>

template <typename T>
class Mempool{
    public:
        /*Object must be created with valid size , no copy and assignment allowed */
        Mempool()=delete;
        Mempool(const Mempool&) = delete ;
        Mempool& operator = (const Mempool&) = delete ;
    private:
        T *_base;
        size_t _poolSize;
        int *_allocation;
        bool _isOk;
    public:
        Mempool(size_t argPoolSize):_poolSize{argPoolSize},_base{nullptr},_allocation{nullptr},_isOk{false}{
            if(_poolSize<1){ _poolSize=0; }
            if(_poolSize){
                _base = reinterpret_cast<T*>(new (std::nothrow) char[_poolSize*sizeof(T)]);
                _allocation = new (std::nothrow) int[_poolSize];
                if(_base!=nullptr && _allocation!=nullptr) {memset(_allocation,0,_poolSize*sizeof(int)); _isOk=true;}
            }
        }
        
        T* getSeat(){
            size_t count=0;
            while(count<_poolSize){
                if(!_allocation[count]){
                    _allocation[count]=1;
                    return static_cast<T*>(new (static_cast<void*>(_base+count)) T());
                }
                ++count;
            }
            return nullptr;
        }
        bool freeSeat(T* pArgSeat){
            pArgSeat->~T();
            _allocation[(_base-pArgSeat)/sizeof(T)]=0;
        }
        ~Mempool(){
            char *tmp  = reinterpret_cast<char*>(_base);
            delete []tmp;
            delete []_allocation;
        }
};
#endif
