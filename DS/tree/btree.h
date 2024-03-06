#include<iostream>
#include "node.h"
#include "string"
template<typename T>
class SimpleBTree{
    TNode<T> *root;

    bool deforst(TNode<T> *root){
        if(!root) return false;
        
        if(root->left==nullptr && root->right==nullptr){
            delete root;return true ;
        }
        if(root->left!=nullptr && !deforst(root->left)) return false;
        if(root->right!=nullptr && !deforst(root->right)) return false;
        return true ;
    }

    public:
        SimpleBTree():root{nullptr}{};
        SimpleBTree(const SimpleBTree&)=delete;
        SimpleBTree& operator = (const SimpleBTree&) = delete ;
        ~SimpleBTree(){ if(root && !deforst(root)) std::cout<<"memory leak"<<std::endl; }
        SimpleBTree(SimpleBTree&&)=delete;
        SimpleBTree& operator = (SimpleBTree&&) = delete ;
        
        bool addNode(const T &argData){
            TNode<T> *t = new (std::nothrow) TNode<T>(argData);
            if(!root){root=t; return true ;}
            TNode<T> *tmp = root;
            while(tmp){
                if(argData<tmp->data){
                    if(!tmp->left) tmp->left=t;
                }else if (argData>tmp->data){
                    if(!tmp->right) tmp->right=t;
                }else{
                    return true ;
                }
            }
        }
        
        void printTree(){return _printTree(root);}
        void _printTree(TNode<T>* _root)const{
            if(!_root) return ;
            _printTree(_root->left);
            std::cout<<_root->data<<",";
            _printTree(_root->right);
            std::cout<<std::endl;
            return;
        }
};