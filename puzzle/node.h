#ifndef _NODE_
#define _NODE_

class node{
    
};

class Node{
    protected:
        int _data;
        Node *_next;
        Node *_previous;
    public:
        Node(int data, Node *nxt=nullptr,Node *pre=nullptr){
            _data =data;
            _next= nxt;
            _previous = pre;
        }
    
        int getData()const{return _data;}
        Node* getNext() const {return _next;}
        Node* getPrevious() const {return _previous;}

        int setData(int argData){ return _data=argData;}
        bool setNext(Node *addr){_next =  addr;}
        bool setPrevious(Node *addr){_previous =  addr;}
        
};

class SingleLL{
    public:
        SingleLL(){
            _head=nullptr;
        }
        
        void addNode(int data){
            if(_head==nullptr){
                _head = new Node(data);
                return;
            } 
            _head = new Node(data,_head);
        }
        
        bool isEmpty()const{return _head==nullptr?true:false;}
        int getHeadData()const {return _head->getData();}
        
        void displayList(){
            Node *tmp = _head;
            while(tmp != nullptr){
                std::cout<<"["<<tmp->getData()<<"]->";
                tmp=tmp->getNext();
            }
            std::cout<<std::endl;
        }
        
        int returnMid(){
            Node *tmp = _head,
                *mid=_head;
            bool ticker= false;
            
            while(tmp!=nullptr){
                tmp= tmp->getNext();
                if(ticker){
                    mid=mid->getNext();
                }
                ticker=!ticker;
            }
            if(ticker) std::cout<<"EVEN LIST"<<std::endl; else std::cout<<"ODD LIST"<<std::endl;
            return mid!=nullptr?mid->getData():0;
        }
    private:
        Node *_head;
};

#endif