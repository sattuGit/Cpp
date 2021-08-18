#include "doubly.h"
template<class T>
bool Doubly<T>::addNode(T &_arg ,int pos=0, T &posNode=nullptr )
{
    T *newNode =  new (std::nothrow) TDNode<T>(_arg);
    if (!newNode){ return false;}
    if(!_head){/*first node*/
                _head = newNode;
    }else{
        if(!(pos || posNode)){
        /*Default case , append at end */

        }
    }
    return true ;
} 