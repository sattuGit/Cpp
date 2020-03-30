#ifndef SINGLE_LINK_LIST_SIMPLE_
#define SINGLE_LINK_LIST_SIMPLE_

struct Node{
	public :
		Node(int argData=0){
			nextNode = nullptr;
			data = argData;
		}
		~Node(){
			std::cout<<"Node is going to vanish with data "<<getData()<<std::endl;
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
		int data;	
		Node *nextNode;
};

#endif
