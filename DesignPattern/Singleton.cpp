#include<mutex>
#include<thread>
#include<iostream>

static std::mutex _singleMux;
class Single{
	static Single *_pRaw;
	static size_t _refCount;
	//Single()=default ;
	//~Single()=default;
	Single(){std::cout<<"Constructor"<<std::endl;}
	~Single(){std::cout<<"Destructor"<<std::endl;}
	public:
		Single(const Single&)=delete ;
		Single& operator=(const Single&) =delete;
		Single& operator=(Single&&) =delete;
		Single(Single&&)=delete ;
	static Single* getInst(){
		if(!_pRaw){
		    std::unique_lock<std::mutex> lock(_singleMux);
		    if(!_pRaw)
			_pRaw = new (std::nothrow)  Single();
			++_refCount;
			std::cout<<"New getInst "<<_refCount<<std::endl;
			return _pRaw;
			lock.unlock();
		}
		std::unique_lock<std::mutex> lock(_singleMux);
		++_refCount;
		lock.unlock();
		std::cout<<"getInst "<<_refCount<<std::endl;
		return _pRaw;
	}
	static bool freeSing(){
		std::unique_lock<std::mutex> lock(_singleMux);
		if(_pRaw!=nullptr &&( --_refCount<=0)) {
		    //std::cout<<"getInst "<<_refCount<<std::endl;
			if (_pRaw) delete _pRaw;
			_pRaw=nullptr;
			lock.unlock();
			return true;
		}
		std::cout<<"Del "<<_refCount<<std::endl;
		lock.unlock();
		return false;
	}
	
	static size_t getRefCount() {return _refCount;}
	static void reset(){
	    std::unique_lock<std::mutex> lock(_singleMux); 
	    if(_pRaw) delete _pRaw; 
	    _refCount=0; 
	    _pRaw=nullptr; 
	    lock.unlock();
	}
};
Single* Single::_pRaw = nullptr;
size_t Single::_refCount = 0;



int main(){
    std::thread t1([]()->void{int count=1000;while(count-->0){
        Single::getInst();
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    });
    std::thread t2([]()->void{int count=1000;while(count-->0){
        Single::getInst();
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    });
    std::thread t3([]()->void{int count=3000;while(count-->0){
        std::cout<<(Single::freeSing()?"ACTUAL FREE ":"DUMMY FREE ")<<std::flush;
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }});
    if(t1.joinable()) t1.join();
    if(t2.joinable()) t2.join();
    if(t3.joinable()) t3.join();
    std::cout<<"---------------"<<Single::getRefCount()<<std::endl;
    Single::reset();
    
    return EXIT_SUCCESS;
}