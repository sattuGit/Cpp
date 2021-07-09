#ifndef _SHARE_SO_DYNAMIC_
#define _SHARE_SO_DYNAMIC_
class Arthametic{
    private :
        int _data;
    public:
        Arthametic(int _arg=0):_data{_arg}{std::cout<<"Construction"<<std::endl;}
        ~Arthametic(){std::cout<<"Destruction"<<std::endl;}
        Arthametic(const Arthametic&) = delete;
        Arthametic& operator = (const Arthametic&) = delete;
        int getData()const {return _data;}
        void setData(const int& arg){_data=arg;}        
};

Arthametic* getArthametic(int);
void delArthametic(Arthametic*);
#endif