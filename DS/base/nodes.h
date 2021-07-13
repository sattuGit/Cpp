/*
 * nodes.h
 *
 *  Created on: Apr 3, 2020
 *      Author: satendra
 */

#ifndef NODES_H_
#define NODES_H_
#include <iostream>

struct Node{
	public :
		Node(int argData=0){
			nextNode = nullptr;
			data = argData;
		}
		~Node(){
			//std::cout<<"Node is going to vanish with data "<<getData()<<std::endl;
		}
		int getData(){
			return data;
		}
		void setData(int arg){
			data=arg;
		}
		void setLink(Node *pNode){
			nextNode=pNode;
		}
		Node * getLink(){
			return nextNode;
		}
	private:
		int  data;
		Node *nextNode;
};

struct LoopNode {
public:
	LoopNode(void* add ){
		address		= 	add		;
		nextNode	=	nullptr	;
		//cout<<"Construction"<<endl;
	}
	~LoopNode(){
		//std::cout<<"Node is going to vanish with data "<<getData()<<std::endl;
	}
	LoopNode* getNext(){
		return nextNode;
	}
	void setNext(LoopNode* next){
		nextNode=next;
	}
	void* getData(){
		return address;
	}
	void setData(void *add){
		address=add;
	}

private:
	void* address;	//non GNU data type to hold int address i.e. can hold address C++11 onward
	LoopNode *nextNode;
};

/*Simple dubbly ll node, canbe use in singly as well (but lead memory waste)*/
class DNode{
    protected:
        int _data;
        DNode *_next;
        DNode *_previous;
    public:
        DNode(int data, DNode *nxt=nullptr,DNode *pre=nullptr){
            _data =data;
            _next= nxt;
            _previous = pre;
        }
    
        int getData()const{return _data;}
        DNode* getNext() const {return _next;}
        DNode* getPrevious() const {return _previous;}

        int setData(int argData){ return _data=argData;}
        void setNext(DNode *addr){_next =  addr;}
        void setPrevious(DNode *addr){_previous =  addr;}        
		DNode* operator++ (){
			return this->getNext();
		}
		DNode* operator++ (int){
			return this->getNext();
		}
};


/*Template class for doubly node */
template<class T>
class TDNode{
    protected:
        T _data;
        TDNode *_next;
        TDNode *_previous;
    public:
        TDNode(T data, TDNode *nxt=nullptr,TDNode *pre=nullptr){
            _data =data;  //incase of class with pointer , assignment shoudl be overloaded 
            _next= nxt;
            _previous = pre;
        }
    
        T getData()const{return _data;}
        TDNode* getNext() const {return _next;}
        TDNode* getPrevious() const {return _previous;}

        void setData(T argData){ _data=argData;}
        void setNext(TDNode *addr){_next =  addr;}
        void setPrevious(TDNode *addr){_previous =  addr;}        
		TDNode* operator++ (){
			return this->getNext();
		}
		TDNode* operator++ (int){
			return this->getNext();
		}
};
#endif /* NODES_H_ */
