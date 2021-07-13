/*
Author : Satendra K gupta
        13 July 2021 
    Simple program for demostrate doubly linklist
    www.satendra.info 
*/
#ifndef _SATTU_DLLIST_
#define _SATTU_DLLIST_
#include "../../base/nodes.h"
template<class T>
class Doubly{
    private :
        TDNode<T> *_head;
        TDNode<T> *_last; /*This is not the Doubly way to do it , but its o(1) for fast insert*/
        size_t     _size; /*to hold element count */
    public:
        Doubly():_head{nullptr},_last{nullptr},_size{0}{}
        virtual ~Doubly(){};
        virtual bool comapre(T &arg1,T &arg2){return true;}
        virtual bool addNode(T &dataArg,int pos=-1,T &posElement =nullptr) //data,postition, position element
        {
            T *newNode =  new (std::nothrow) TDNode<T>(dataArg);
            if (!newNode){ return false;}
            
            /*Empty list*/
            if(!_head){
                _head = newNode;
                _last=newNode;
                ++_size;
                return true ;
            }
            
            /*Default case , append at end */
            else if(!(pos==-1 || posElement=nullptr)){
                newNode->setPrevious(_last);
                _last->setNext(newNode);
                _last=newNode;
                ++_size;
                return true;
            }
            
            /*at specific postion*/
            else if(pos<0 || pos> _size){return false;}
            else{ 
                    /*Valid postion*/
                /* we are trying to cut down search time in worst case it would be o(n/2)*/
                if(pos==0){
                    newNode->setNext(_head);
                    _head->setPrevious(newNode);
                    _head=newNode;
                    ++_size;    
                    return true;
                }else{
                    int mid = _size/2;
                    if(mid == pos){
                        
                    }else if (mid > pos){

                    }else {

                    }
                }
                    return false;
                }
                 
            }
            return false ;
        }
        virtual T    removeNode(int);
        virtual void display()  ;    
};
//template<class T>
//bool Doubly<T>::addNode(T &_arg ,int pos=0, T &posNode=nullptr )
 
#endif 