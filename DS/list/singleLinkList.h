#ifndef NODES_LINK_LIST_
#define NODES_LINK_LIST_

#include "nodes.h"

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
		void rev();
		unsigned int getListCount(){return nodeCount;}
	private :
		unsigned int nodeCount;
		Node * getNode(int);
		Node *head;
};

#endif