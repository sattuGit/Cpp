#include<iostream>
#include "singleLinkList.h"
using namespace std;

class SLList{
	public 	:
		SLList(){
			head = nullptr;
			nodeCount=0;
		}
		~SLList(){
			cout<<"distructer SSList"<<endl;
			// need to delete memory by trversing  
			Node *tmp=nullptr;
			while (head){
				tmp=head->getLink();
				delete head ;
				head = tmp;
			}
		}
		bool addNodex(int arg);
		bool addNode(int arg, int pos=1);
		void display();
		bool del(int);
		unsigned int getListCount(){return nodeCount;}
	private :
		unsigned int nodeCount;
		Node * getNode(int);
		Node *head;
};

Node * SLList::getNode(int arg){
	Node *tmp = new (std::nothrow) Node(arg);
	return tmp;
}

bool SLList::del(int pos=1){
	cout<<getListCount()<<endl;
	if(pos<1 || pos > getListCount()){ cout<<"Invalid position : List size is  "<<getListCount()<<":"<<pos<<endl;return false;}
	Node *t=head;
	for(int i=0;i<pos-2;++i){
		if(t)t=t->getLink();
	}
	if(t)cout<<t->getData()<<endl;else cout<<"null point\n";
	if(pos==1){
		if(head)head = head->getLink();
		delete t;
	}else{
		 
		Node *tt=t->getLink();
		t->setLink(t->getLink()->getLink());
		delete tt;
	}
	--nodeCount;
	return true ;
}

void SLList::display(){
	Node *tmpHead = head;
	while(tmpHead){
		cout<<"["<<tmpHead->getData()<<"]->";
		tmpHead=tmpHead->getLink();
	}
	cout<<"NULL\n";	
}

bool SLList::addNode(int arg, int pos){
	cout<<"arg "<<arg<<" pos "<<pos<<endl;
	if((pos>getListCount()+1) || pos<1) return false;	//BoundChecking
	Node *newNode = getNode(arg);
	if(!newNode){
		cout<<"Insufficient memory\n";
		return false;
	}

	Node 	*tmp 	= 	head;
	if(pos==1){
		newNode->setLink(head);
		head=newNode;
	}else{
		for(int i=1;i<(pos-1);++i)if (tmp)tmp= tmp->getLink();
		newNode->setLink(tmp->getLink());
		tmp->setLink(newNode);
	}
	
	++nodeCount;
	return true ;
}

int main(){
	SLList *sl= new SLList();
	unsigned short choice =1,pos=1 ;
	int data;
	while(choice){
	pos=1;
	cout<<"Enter your choice \n";
	cout<<" 1 for add new node at specific position \n";
	cout<<" 2 for add new node at top \n";
	cout<<" 3 for Remove node at specific position \n";
	cout<<" 4 for Remove node at top \n";
	cout<<" 9 for Display  \n";
	cout<<" Any other for Exit \n";
	cin>>choice;
		switch(choice){
			case 1:	cout<<"Pleases provied position for new node \n";cin >>pos;
			case 2:	cout<<"Pleases provied value of node\n";cin >>data;
					sl->addNode(data,pos);
					break;
			case 3: cout<<"Pleases provied position of node to remove \n";cin >>pos;
			case 4: sl->del(pos);break;
			case 9: sl->display(); break;
			default: choice =0;
		}
	}
	delete sl;
	return 0;
}