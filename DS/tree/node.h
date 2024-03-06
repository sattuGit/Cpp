#ifndef __SATTU_TREEN__
#define __SATTU_TREEN__

template<typename T>
struct TNode{
    T data;
    TNode *left;
    TNode *right;
    TNode(const T &arg):data{arg}{}
};
#endif 