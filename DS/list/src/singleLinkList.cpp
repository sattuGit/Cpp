#include<iostream>
#include "singleLinkList.h"
#include "linkLoop.h"
using namespace std;
void SLList::testLoop(){
	Node	* tmp = head ;
	LinkLoop *llp = new LinkLoop();
	while (tmp){
		if(!llp->addUnique(tmp)){
			cout<<"Loop found....@"<<tmp->getData()<<endl;
			cout<<"List is going to repair ....\n";
			{
				Node *ptrTmpRepair = head ;
				while(ptrTmpRepair->getLink()!=tmp)ptrTmpRepair=ptrTmpRepair->getLink();
				ptrTmpRepair->setLink(nullptr);
			}
			return ;
		}
		tmp=tmp->getLink();
	}
	cout<<"No Cycle found ... \n";
	/*free memory */
	delete llp;
}

void SLList::makeLoop(){
	Node *tmp =head ;
	while (tmp){
		//cout<<" "<<tmp->getData()<<endl;
		if(tmp->getLink()){
			tmp=tmp->getLink();
		}else
			break;
	}
	//cout<<"XXX "<<tmp->getData()<<" XXX"<<tmp->getLink();
	tmp->setLink(head);
}
void SLList::rev(){
	if((!head) || (!(head->getLink()) )) return ;
	Node *tmp3,*tmp2,*tmp1;
	tmp1 = head ;
	tmp2=tmp1->getLink();
	if(tmp2)tmp3=tmp2->getLink();
	
	while(tmp2 || tmp3 ){
		if(tmp2)tmp2->setLink(tmp1);
		tmp1=tmp2;
		tmp2=tmp3;
		if(tmp3)tmp3=tmp3->getLink();
	}
	head->setLink(nullptr);
	head = tmp1;
}
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
