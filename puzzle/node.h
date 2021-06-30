#ifndef _SINGLE_LL_
#define _SINGLE_LL_


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