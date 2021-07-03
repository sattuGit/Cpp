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
        bool setNext(DNode *addr){_next =  addr;}
        bool setPrevious(DNode *addr){_previous =  addr;}        
		DNode* operator++ (){
			return this->getNext();
		}
		DNode* operator++ (int){
			return this->getNext();
		}
};
#endif /* NODES_H_ */
